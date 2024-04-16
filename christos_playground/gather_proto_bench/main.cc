#include"person.pb.h"
#include"scatter_gather.h"
#include"iaa_comp.h"

static constexpr size_t kNofIterations = 10000;
static constexpr size_t kNofWarmUpIterations = 100;

#define BUFFER_SIZE 4096

int main () {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // initialize iaa jobs
	iaa_init_jobs(qpl_path_hardware);
	//iaa_init_jobs(qpl_path_software);

    std::vector<M> messages;
    std::vector<std::string> ser_outs;
    // Gather schemas
    std::vector<ScatterGather::Schema> schemas;
    // IAA utility arrays
    uint8_t** compressed   = new uint8_t*[kNofIterations];
    uint8_t** decompressed = new uint8_t*[kNofIterations];
    for (size_t i = 0; i < kNofIterations; ++i) {
        compressed[i]   = new uint8_t[BUFFER_SIZE];
        decompressed[i] = new uint8_t[BUFFER_SIZE];
    }
    // arrays for keeping output size feedback from IAA
    uint32_t* comprOutputSize   = new uint32_t[kNofIterations];

    for (size_t i = 0; i < kNofIterations; ++i) {
        M m;
        ScatterGather::Schema schema;
        // <------------ SETTERS ------>

        messages.push_back(m);
        ser_outs.push_back("");

        // <------------ SCHEMA ------>

        schemas.push_back(schema);
    }

    //
    // Benchmark serialize.
    //
    // Warm-up.
    for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
    if (!messages[i].SerializeToString(&ser_outs[i])) {
        std::cerr << "Benchmark error." << std::endl;
        return -1;
    }
    }

    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
    if (!messages[i].SerializeToString(&ser_outs[i])) {
        std::cerr << "Benchmark error." << std::endl;
        return -1;
    }
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto took_ns =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Serialization took = "
            << took_ns / (messages.size() - kNofWarmUpIterations)
            << " [ns], size = " << ser_outs[0].size() << " Bytes" << std::endl;


    ScatterGather scagatherer;
    size_t out_size = 0;
    std::vector<std::vector<uint8_t>> scatter_outs(kNofIterations, std::vector<uint8_t>(BUFFER_SIZE, 0));

    for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
        scagatherer.GatherWithMemCpy(schemas[i], scatter_outs[i].data(), &out_size);
        if (compress_with_IAA(scatter_outs[i].data(), out_size, compressed[i], BUFFER_SIZE, &comprOutputSize[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }

    begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < kNofIterations; ++i) {
        scagatherer.GatherWithMemCpy(schemas[i], scatter_outs[i].data(), &out_size);
        if (compress_with_IAA(scatter_outs[i].data(), out_size, compressed[i], BUFFER_SIZE, &comprOutputSize[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }
    end = std::chrono::steady_clock::now();
    took_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Gather+IAA took : " << took_ns / kNofIterations << " nanoseconds" << std::endl;
    std::cout << "Gathered size : " << out_size << " bytes" << std::endl;
    std::cout << "Compressed size : " << comprOutputSize[0] << " bytes" << std::endl;

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

  // free existing iaa jobs
	iaa_fini_jobs();

    return 0;
}