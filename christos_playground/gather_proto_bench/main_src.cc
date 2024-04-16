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
	//iaa_init_jobs(qpl_path_hardware);
	iaa_init_jobs(qpl_path_software);

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
		(&m)->set_f1(6438595 + (i * 1) % 8);
		(&m)->set_f2(61 + (i * 1) % 8);
		(&m)->set_f3(52966 + (i * 1) % 8);
		(&m)->set_f4(221 + (i * 1) % 8);
		(&m)->set_f5(44883 + (i * 1) % 8);
		(&m)->set_f6(20460 + (i * 1) % 8);
		(&m)->set_f7(194 + (i * 1) % 8);
		(&m)->set_f8(10982980 + (i * 1) % 8);
		(&m)->set_f9(2618133637 + (i * 1) % 8);
		(&m)->set_f10(45420 + (i * 1) % 8);
		(&m)->set_f11(951027 + (i * 1) % 8);
		(&m)->set_f12(44146 + (i * 1) % 8);
		(&m)->set_f13(42 + (i * 1) % 8);
		(&m)->set_f14(20123 + (i * 1) % 8);
		(&m)->set_f15(49871 + (i * 1) % 8);
		(&m)->set_f16(11093382 + (i * 1) % 8);
		(&m)->set_f17(13996489 + (i * 1) % 8);
		(&m)->set_f18(223 + (i * 1) % 8);
		(&m)->set_f19(184 + (i * 1) % 8);
		(&m)->set_f20(86 + (i * 1) % 8);
		(&m)->mutable_f21()->set_f1(124 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f2(110 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f3(232 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f4(155 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f5(1385200035 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f6(772226 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f7(3291332511 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f8(810984 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f9(65152 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f10(193 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f11(8637444 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f12(208 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f13(36078 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f14(1798470504 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f15(35468 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f16(2983916734 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f17(157 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f18(2159757442 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f19(2832040975 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f20(6362379 + (i * 2) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f1(24359 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f2(1078238326 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f3(8564159 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f4(130 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f5(2200817 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f6(205 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f7(1172728234 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f8(12532390 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f9(52891 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f10(25 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f11(18880 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f12(54928 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f13(15598678 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f14(26 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f15(140 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f16(4990223 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f17(1503342709 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f18(14209 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f19(10750393 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f20(2028280123 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f1(794107020 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f2(31150 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f3(9318460 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f4(37436 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f5(54326 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f6(1857858053 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f7(1370681644 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f8(166 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f9(9831 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f10(7504217 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f11(45331 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f12(16701860 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f13(8807 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f14(1591056647 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f15(117 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f16(2921723560 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f17(147 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f18(78 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f19(18950 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f20(3338665 + (i * 3) % 8);
		(&m)->mutable_f22()->set_f1(38 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f2(4486 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f3(1576059694 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f4(912 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f5(1938529 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f6(433074588 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f7(63799 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f8(3765119 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f9(235 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f10(2248142259 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f11(7297 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f12(33241 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f13(175 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f14(20240 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f15(2589867 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f16(30 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f17(3290427 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f18(126 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f19(15 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f20(190 + (i * 2) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f1(7288306 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f2(22852 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f3(28904 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f4(8192798 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f5(60272 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f6(5442069 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f7(5987088 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f8(240 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f9(2043 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f10(199 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f11(157 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f12(1862916526 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f13(117 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f14(410232000 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f15(182 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f16(23361 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f17(51 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f18(2770081962 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f19(13767 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f20(510303628 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f1(813511612 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f2(11238715 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f3(2632426639 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f4(47127 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f5(4152699031 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f6(60 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f7(8850688 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f8(16770 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f9(1629859 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f10(276031729 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f11(117 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f12(98 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f13(6263543 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f14(8643951 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f15(169 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f16(147 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f17(17590 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f18(16720144 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f19(2805855704 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f20(704603 + (i * 3) % 8);

        messages.push_back(m);
        ser_outs.push_back("");

        // <------------ SCHEMA ------>
	schema.push_back(std::make_tuple(reinterpret_cast<const unsigned char*>((&m)->mutable_f21()), sizeof(*((&m)->mutable_f21()))));
	schema.push_back(std::make_tuple(reinterpret_cast<const unsigned char*>((&m)->mutable_f21()->mutable_f21()), sizeof(*((&m)->mutable_f21()->mutable_f21()))));
	schema.push_back(std::make_tuple(reinterpret_cast<const unsigned char*>((&m)->mutable_f21()->mutable_f22()), sizeof(*((&m)->mutable_f21()->mutable_f22()))));
	schema.push_back(std::make_tuple(reinterpret_cast<const unsigned char*>((&m)->mutable_f22()), sizeof(*((&m)->mutable_f22()))));
	schema.push_back(std::make_tuple(reinterpret_cast<const unsigned char*>((&m)->mutable_f22()->mutable_f21()), sizeof(*((&m)->mutable_f22()->mutable_f21()))));
	schema.push_back(std::make_tuple(reinterpret_cast<const unsigned char*>((&m)->mutable_f22()->mutable_f22()), sizeof(*((&m)->mutable_f22()->mutable_f22()))));

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