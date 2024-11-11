#include"reqsim.h"

RequestSim::RequestSim(size_t max_requests, size_t buffer_size, size_t schema_length, IAAComp* iaa, qpl_path_t path)
    : MAX_REQUESTS(max_requests), BUFFER_SIZE(buffer_size), SCHEMA_LENGTH(schema_length), iaa(iaa)
{
    if (iaa == nullptr){
        std::cerr << "IAAComp object is not provided. Creating a new one." << std::endl;
        this->iaa = new IAAComp(path);
    }

    // Resize gather_outs based on MAX_REQUESTS and BUFFER_SIZE
    for (size_t i = 0; i < MAX_REQUESTS; ++i) {
        std::vector<uint8_t> gather_out(BUFFER_SIZE, 0);
        gather_outs.push_back(gather_out);
    }

    // IAA utility arrays
    compressed   = new uint8_t*[MAX_REQUESTS];
    decompressed = new uint8_t*[MAX_REQUESTS];
    for (size_t i = 0; i < MAX_REQUESTS; ++i) {
        compressed[i]   = new uint8_t[BUFFER_SIZE];
        decompressed[i] = new uint8_t[BUFFER_SIZE];
    }
    // arrays for keeping output size feedback from IAA
    comprOutputSize   = new uint32_t[MAX_REQUESTS];
    decomprOutputSize = new uint32_t[MAX_REQUESTS];

    // Initialize Sender messages
    for (size_t i = 0; i < MAX_REQUESTS; ++i) {
        M m;

        // <------------ SETTERS ------>
		(&m)->set_f1(2025514 + (i * 1) % 8);
		(&m)->set_f2(201 + (i * 1) % 8);
		(&m)->set_f3(1479798053 + (i * 1) % 8);
		(&m)->set_f4(517044834 + (i * 1) % 8);
		(&m)->set_f5("CNNST2FVVN");

        //messages[i] = m;
        sender_messages.push_back(m);
        ser_outs.push_back("");
    }
    // Allocate Receiver messages for protobuf requests
    for (size_t i = 0; i < MAX_REQUESTS; ++i) {
        M m;
        deser_messages_out.push_back(m);
    }
    // Allocate Receiver messages for IAA requests
    for (size_t i = 0; i < MAX_REQUESTS; ++i) {
        M m;
        out_messages.push_back(m);
    }
}

RequestSim::~RequestSim() {
    delete iaa;
    for (size_t i = 0; i < MAX_REQUESTS; ++i) {
        delete[] compressed[i];
        delete[] decompressed[i];
    }
    delete[] compressed;
    delete[] decompressed;
    delete[] comprOutputSize;
    delete[] decomprOutputSize;
}

int RequestSim::proto_ser_request(size_t i) {
    assert(i < MAX_REQUESTS);
    std::chrono::steady_clock::time_point begin, end;
    std::chrono::nanoseconds duration;
    begin = std::chrono::steady_clock::now();

    //Serialize
    auto outcome = sender_messages[i].SerializeToString(&ser_outs[i]);
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    serialization_durations.push_back(duration);
    if (!outcome) {
        std::cerr << "Failed to Serialize." << std::endl;
        return -1;
    }
    return 0;
}

int RequestSim::proto_deser_request(size_t i) {
    assert(i < MAX_REQUESTS);
    std::chrono::steady_clock::time_point begin, end;
    std::chrono::nanoseconds duration;

    //Deserialize
    begin = std::chrono::steady_clock::now();
    auto outcome = deser_messages_out[i].ParseFromString(ser_outs[i]);
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    deserialization_durations.push_back(duration);
    if (!outcome) {
        std::cerr << "Failed to Deserialize." << std::endl;
        return -1;
    }
    return 0;
}

int RequestSim::tachidromos_ser_request(size_t i) {
    assert(i < MAX_REQUESTS);
    assert(iaa != nullptr);
    std::chrono::steady_clock::time_point begin, end;
    std::chrono::nanoseconds duration;

    // GATHER SCHEMA GENERATION + GATHER + COMPRESSION
    // 1. Gather Schema Generation
    ScatterGather::Schema gather_schema;
    std::vector<size_t> sizes;
    gather_schema.reserve(SCHEMA_LENGTH);
    sizes.reserve(SCHEMA_LENGTH);

    begin = std::chrono::steady_clock::now();
    sender_messages[i].generate_schema(gather_schema);
    sender_messages[i].generate_scatter_sizes(sizes);
    end = std::chrono::steady_clock::now();

    gather_schemas.push_back(gather_schema);
    sizes_for_scatter.push_back(sizes);
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    gather_schema_durations.push_back(duration);

    // 2. Gather
    size_t out_size = 0;
    begin = std::chrono::steady_clock::now();
    auto outcome = scagatherer.GatherWithMemCpy(gather_schemas[i], gather_outs[i].data(), &out_size);
    end = std::chrono::steady_clock::now();
    if (outcome) {
        std::cerr << "Failed to gather" << std::endl;
        return -1;
    }
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    gather_durations.push_back(duration);

    // 3. Compression
    begin = std::chrono::steady_clock::now();
    outcome = iaa->compress(gather_outs[i].data(), out_size, compressed[i], BUFFER_SIZE, &comprOutputSize[i]);
    end = std::chrono::steady_clock::now();
    if (outcome) {
        std::cerr << "Benchmark error." << std::endl;
        return -1;
    }
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    compression_durations.push_back(duration);
    return 0;
}

int RequestSim::tachidromos_deser_request(size_t i) {
    assert(i < MAX_REQUESTS);
    assert(iaa != nullptr);
    std::chrono::steady_clock::time_point begin, end;
    std::chrono::nanoseconds duration;

    // MEMORY_ALLOCATION + SCATTER SCHEMA GENERATION + DECOMPRESSION + SCATTER
    // 1. Memory Allocation
    std::string dummy_str("a", sizes_for_scatter[0][1]);
    begin = std::chrono::steady_clock::now();
    // <------------ STRING SETTERS ------>
		{ // DEPTH = 1, WIDTH = 0
		(&out_messages[i])->set_f5(dummy_str);
		}
    end = std::chrono::steady_clock::now();

    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    allocation_durations.push_back(duration);

    // 2. Scatter Schema Generation
    ScatterGather::Schema scatter_schema;
    scatter_schema.reserve(SCHEMA_LENGTH);
    begin = std::chrono::steady_clock::now();
    out_messages[i].generate_schema(scatter_schema);
    end = std::chrono::steady_clock::now();
    scatter_schemas.push_back(scatter_schema);
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    scatter_schema_durations.push_back(duration);

    // 3. Decompression
    begin = std::chrono::steady_clock::now();
    auto outcome = iaa->decompress(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i]);
    end = std::chrono::steady_clock::now();
    if (outcome) {
        std::cerr << "Benchmark error." << std::endl;
        return -1;
    }
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    decompression_durations.push_back(duration);

    // 4. Scatter
    begin = std::chrono::steady_clock::now();
    outcome = scagatherer.ScatterWithMemCpy(decompressed[i], scatter_schemas[i]);
    end = std::chrono::steady_clock::now();
    if (outcome) {
        std::cout << "Failed to scatter" << std::endl;
        return -1;
    }

    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    scatter_durations.push_back(duration);
    return 0;
}

bool RequestSim::verify_correctness() {
    bool all_correct = true;
    for (size_t i = 0; i < MAX_REQUESTS && all_correct; ++i) {
        all_correct = google::protobuf::util::MessageDifferencer::Equivalent(sender_messages[i], out_messages[i]);
    }
    return all_correct;
}

void RequestSim::report_timings(std::vector<std::chrono::nanoseconds> perfs, std::string stat) {
    std::cout << stat << "(ns)";
    for (auto perf: perfs) std::cout << ", " << perf.count();
    std::cout << "\n";
}

void RequestSim::report() {
    report_timings(serialization_durations, "serialization");
    report_timings(deserialization_durations, "deserialization");
    report_timings(gather_schema_durations, "gather_schemas");
    report_timings(gather_durations, "gather");
    report_timings(compression_durations, "compression");
    report_timings(scatter_schema_durations, "scatter_schemas");
    report_timings(scatter_durations, "scatter");
    report_timings(decompression_durations, "decompression");
    report_timings(allocation_durations, "allocation");
}