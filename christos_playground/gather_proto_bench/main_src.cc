#include <google/protobuf/util/message_differencer.h>

#include"person.pb.h"
#include"scatter_gather.h"
#include"iaa_comp.h"

static constexpr size_t kNofIterations = 10000;
static constexpr size_t kNofWarmUpIterations = 100;

#define BUFFER_SIZE 16384

int main () {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // initialize iaa jobs
	iaa_init_jobs(qpl_path_hardware);
	//iaa_init_jobs(qpl_path_software);

    std::vector<M> messages;
    //messages.reserve(kNofIterations);
    std::vector<std::string> ser_outs;
    // IAA utility arrays
    uint8_t** compressed   = new uint8_t*[kNofIterations];
    uint8_t** decompressed = new uint8_t*[kNofIterations];
    for (size_t i = 0; i < kNofIterations; ++i) {
        compressed[i]   = new uint8_t[BUFFER_SIZE];
        decompressed[i] = new uint8_t[BUFFER_SIZE];
    }
    // arrays for keeping output size feedback from IAA
    uint32_t* comprOutputSize   = new uint32_t[kNofIterations];
    uint32_t* decomprOutputSize = new uint32_t[kNofIterations];

    for (size_t i = 0; i < kNofIterations; ++i) {
        M m;

        // <------------ SETTERS ------>
		(&m)->set_f1(3417066274 + (i * 1) % 8);
		(&m)->set_f2(67 + (i * 1) % 8);
		(&m)->set_f3(3030226933 + (i * 1) % 8);
		(&m)->set_f4(105 + (i * 1) % 8);
		(&m)->set_f5(36945 + (i * 1) % 8);
		(&m)->set_f6(27260 + (i * 1) % 8);
		(&m)->set_f7(64175 + (i * 1) % 8);
		(&m)->set_f8(9848367 + (i * 1) % 8);
		(&m)->set_f9(10869356 + (i * 1) % 8);
		(&m)->set_f10(56926 + (i * 1) % 8);
		(&m)->set_f11(16661256 + (i * 1) % 8);
		(&m)->set_f12(7304043 + (i * 1) % 8);
		(&m)->set_f13(192 + (i * 1) % 8);
		(&m)->set_f14(134 + (i * 1) % 8);
		(&m)->set_f15(136 + (i * 1) % 8);
		(&m)->set_f16(197 + (i * 1) % 8);
		(&m)->set_f17(15609599 + (i * 1) % 8);
		(&m)->set_f18(699036 + (i * 1) % 8);
		(&m)->set_f19(237 + (i * 1) % 8);
		(&m)->set_f20(189 + (i * 1) % 8);
		(&m)->set_f21(242 + (i * 1) % 8);
		(&m)->set_f22(12174536 + (i * 1) % 8);
		(&m)->set_f23(32736 + (i * 1) % 8);
		(&m)->set_f24(49763 + (i * 1) % 8);
		(&m)->set_f25(244 + (i * 1) % 8);
		(&m)->set_f26(58135 + (i * 1) % 8);
		(&m)->set_f27(811378156 + (i * 1) % 8);
		(&m)->set_f28(10460465 + (i * 1) % 8);
		(&m)->set_f29(15935855 + (i * 1) % 8);
		(&m)->set_f30(25684 + (i * 1) % 8);
		(&m)->set_f31(164 + (i * 1) % 8);
		(&m)->set_f32(7249002 + (i * 1) % 8);
		(&m)->set_f33(24456 + (i * 1) % 8);
		(&m)->set_f34(3926576095 + (i * 1) % 8);
		(&m)->set_f35(1113743503 + (i * 1) % 8);
		(&m)->set_f36(7784 + (i * 1) % 8);
		(&m)->set_f37(2053437655 + (i * 1) % 8);
		(&m)->set_f38(3370458 + (i * 1) % 8);
		(&m)->set_f39(2032044830 + (i * 1) % 8);
		(&m)->set_f40(2572527 + (i * 1) % 8);
		(&m)->set_f41(107 + (i * 1) % 8);
		(&m)->set_f42(5053343 + (i * 1) % 8);
		(&m)->set_f43(3468226711 + (i * 1) % 8);
		(&m)->set_f44(47785 + (i * 1) % 8);
		(&m)->set_f45(1226194312 + (i * 1) % 8);
		(&m)->set_f46(38219 + (i * 1) % 8);
		(&m)->set_f47(50636 + (i * 1) % 8);
		(&m)->set_f48(6496171 + (i * 1) % 8);
		(&m)->set_f49(144 + (i * 1) % 8);
		(&m)->set_f50(14557 + (i * 1) % 8);
		(&m)->set_f51(14824 + (i * 1) % 8);
		(&m)->set_f52(13291871 + (i * 1) % 8);
		(&m)->set_f53(49032 + (i * 1) % 8);
		(&m)->set_f54(53548 + (i * 1) % 8);
		(&m)->set_f55(2053369059 + (i * 1) % 8);
		(&m)->set_f56(133 + (i * 1) % 8);
		(&m)->set_f57(703211 + (i * 1) % 8);
		(&m)->set_f58(12278 + (i * 1) % 8);
		(&m)->set_f59(5989 + (i * 1) % 8);
		(&m)->set_f60(5270804 + (i * 1) % 8);
		(&m)->set_f61(4199982236 + (i * 1) % 8);
		(&m)->set_f62(8426832 + (i * 1) % 8);
		(&m)->set_f63(11278109 + (i * 1) % 8);
		(&m)->set_f64(21 + (i * 1) % 8);
		(&m)->set_f65(225 + (i * 1) % 8);
		(&m)->set_f66(4264277 + (i * 1) % 8);
		(&m)->set_f67(588 + (i * 1) % 8);
		(&m)->set_f68(51992 + (i * 1) % 8);
		(&m)->set_f69(62427 + (i * 1) % 8);
		(&m)->set_f70(1978952550 + (i * 1) % 8);
		(&m)->set_f71(4024065152 + (i * 1) % 8);
		(&m)->set_f72(28804 + (i * 1) % 8);
		(&m)->set_f73(3766717 + (i * 1) % 8);
		(&m)->set_f74(11367615 + (i * 1) % 8);
		(&m)->set_f75(190 + (i * 1) % 8);
		(&m)->set_f76(119938453 + (i * 1) % 8);
		(&m)->set_f77(34 + (i * 1) % 8);
		(&m)->set_f78(206 + (i * 1) % 8);
		(&m)->set_f79(33098 + (i * 1) % 8);
		(&m)->set_f80(16148738 + (i * 1) % 8);
		(&m)->set_f81(3859301542 + (i * 1) % 8);
		(&m)->set_f82(210 + (i * 1) % 8);
		(&m)->set_f83(3031854268 + (i * 1) % 8);
		(&m)->set_f84(2232999285 + (i * 1) % 8);
		(&m)->set_f85(1777847 + (i * 1) % 8);
		(&m)->set_f86(44268 + (i * 1) % 8);
		(&m)->set_f87(15423026 + (i * 1) % 8);
		(&m)->set_f88(181 + (i * 1) % 8);
		(&m)->set_f89(165 + (i * 1) % 8);
		(&m)->set_f90(8725532 + (i * 1) % 8);
		(&m)->set_f91(6408153 + (i * 1) % 8);
		(&m)->set_f92(26982 + (i * 1) % 8);
		(&m)->set_f93(8471069 + (i * 1) % 8);
		(&m)->set_f94(21781 + (i * 1) % 8);
		(&m)->set_f95(115 + (i * 1) % 8);
		(&m)->set_f96(55746 + (i * 1) % 8);
		(&m)->set_f97(485344205 + (i * 1) % 8);
		(&m)->set_f98(5330 + (i * 1) % 8);
		(&m)->set_f99(23115 + (i * 1) % 8);
		(&m)->set_f100(12160 + (i * 1) % 8);

        //messages[i] = m;
        messages.push_back(m);
        ser_outs.push_back("");
    }

    // Gather schemas
    std::vector<ScatterGather::Schema> schemas;
    for (size_t i = 0; i < kNofIterations; ++i) {
        ScatterGather::Schema schema;

        // <------------ SCHEMA ------>
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])), sizeof(*((&messages[i])))));

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

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
        if (!messages[i].SerializeToString(&ser_outs[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto took_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Serialization took = " << took_ns / (kNofIterations - kNofWarmUpIterations) << " [ns], size = " << ser_outs[0].size() << " Bytes" << std::endl;

    //
    // Benchmark deserialize.
    //
    std::vector<M> deser_messages_out;
    for (size_t i = 0; i < messages.size(); ++i) deser_messages_out.push_back(M());

    // Warm-up.
    for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
        if (!deser_messages_out[i].ParseFromString(ser_outs[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }

    begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
        if (!deser_messages_out[i].ParseFromString(ser_outs[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }
    end = std::chrono::steady_clock::now();
    took_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Deserialization took = " << took_ns / (messages.size() - kNofWarmUpIterations) << " [ns], size = " << ser_outs[0].size() << " Bytes" << std::endl;

    // GATHER + COMPRESSION

    ScatterGather scagatherer;
    size_t out_size = 0;
    std::vector<std::vector<uint8_t>> gather_outs(kNofIterations, std::vector<uint8_t>(BUFFER_SIZE, 0));

    // warmup for both
    for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
        if (scagatherer.GatherWithMemCpy(schemas[i], gather_outs[i].data(), &out_size) ) {
            std::cerr << "Failed to gather" << std::endl;
            return -1;
        }
        if (compress_with_IAA(gather_outs[i].data(), out_size, compressed[i], BUFFER_SIZE, &comprOutputSize[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }

    // gather
    begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < kNofIterations; ++i) {
        if (scagatherer.GatherWithMemCpy(schemas[i], gather_outs[i].data(), &out_size) ) {
            std::cerr << "Failed to gather" << std::endl;
            return -1;
        }
    }
    end = std::chrono::steady_clock::now();
    took_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Gathering took : " << took_ns / (kNofIterations - kNofWarmUpIterations) << " nanoseconds" << std::endl;

    // compress
    begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < kNofIterations; ++i) {
        if (compress_with_IAA(gather_outs[i].data(), out_size, compressed[i], BUFFER_SIZE, &comprOutputSize[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }
    end = std::chrono::steady_clock::now();
    took_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Compressing took : " << took_ns / (kNofIterations - kNofWarmUpIterations) << " nanoseconds" << std::endl;

    std::cout << "Gathered size : " << out_size << " bytes" << std::endl;
    std::cout << "Compressed size : " << comprOutputSize[0] << " bytes" << std::endl;

    // DECOMPRESSION + SCATTER

    // decompress
    for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
        if (decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }

    begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
        if (decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }
    end = std::chrono::steady_clock::now();
    took_ns =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Decompression took = " << took_ns / (kNofIterations - kNofWarmUpIterations) << " [ns], size = " << decomprOutputSize[0] << " Bytes" << std::endl;

    // create scatter schemas and output messages
    // output messages after decompression and scatter
    std::vector<M> out_messages;
    //out_messages.reserve(kNofIterations);
    // Scatter schemas
    std::vector<ScatterGather::Schema> scatter_schemas;
    for (size_t i = 0; i < kNofIterations; ++i) {
        M m;
        out_messages.push_back(m);
    }

    for (size_t i = 0; i < kNofIterations; ++i) {
        ScatterGather::Schema schema;

        // <------------ SCATTER SCHEMA ------>
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])), sizeof(*((&out_messages[i])))));

        scatter_schemas.push_back(schema);
    }

    // warmup scatter
    for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
        if (scagatherer.ScatterWithMemCpy(decompressed[i], scatter_schemas[i])) {
            std::cout << "Failed to scatter" << std::endl;
            return -1;
        }
    }

    // do scatter
    begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < kNofIterations; ++i) {
        if (scagatherer.ScatterWithMemCpy(decompressed[i], scatter_schemas[i])) {
            std::cout << "Failed to scatter" << std::endl;
            return -1;
        }
    }
    end = std::chrono::steady_clock::now();
    took_ns =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Scatter took = " << took_ns / (kNofIterations - kNofWarmUpIterations) << " nanoseconds" << std::endl;

    // TODO
    // Verify correctness
    /*
    */
    bool all_correct = true;

    for (size_t i = 0; i < kNofIterations && all_correct; ++i) {
        all_correct = google::protobuf::util::MessageDifferencer::Equals(messages[i], out_messages[i]);
    }

    std::cout << (all_correct ? "ALL CORRECT" : "ERROR: DATA MISSMATCH") << std::endl;

    /*
    */
    // Optional:  Delete all global objects allocated by libprotobuf.
    //google::protobuf::ShutdownProtobufLibrary();

    for (size_t i = 0; i < kNofIterations; ++i) {
        delete[] compressed[i];
        delete[] decompressed[i];
    }
    delete[] compressed;
    delete[] decompressed;

    // free existing iaa jobs
	iaa_fini_jobs();

    return 0;
}
