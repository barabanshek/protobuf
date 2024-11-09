#ifndef REQSIM_H
#define REQSIM_H

#include<string>
#include<vector>
#include<chrono>
#include <google/protobuf/util/message_differencer.h>

#include"person.pb.h"
#include"scatter_gather.h"
#include"iaa_comp.h"

class RequestSim {
private:
    size_t MAX_REQUESTS = 100; // replaces kNofIterations in the original version of the benchmark
    size_t BUFFER_SIZE = 4096;
    size_t SCHEMA_LENGTH = 256;
    
    // pointer to object that encapsulates IAA compression and decompression
    IAAComp* iaa;

    // vectors and time structs for holding performance numbers
    std::vector<std::chrono::nanoseconds> serialization_durations, deserialization_durations;
    std::vector<std::chrono::nanoseconds> gather_durations, scatter_durations;
    std::vector<std::chrono::nanoseconds> gather_schema_durations, scatter_schema_durations;
    std::vector<std::chrono::nanoseconds> compression_durations, decompression_durations;
    std::vector<std::chrono::nanoseconds> allocation_durations;
    // Sender and Receiver messages
    std::vector<M> sender_messages;
    std::vector<M> receiver_messages;
    // Gather utilities
    ScatterGather scagatherer;
    std::vector<ScatterGather::Schema> gather_schemas;
    std::vector<std::vector<size_t>> sizes_for_scatter;
    size_t gather_out_size = 0;
    // IAA Compression utility arrays
    uint8_t** compressed;
    uint32_t* comprOutputSize;
    // IAA Decompression utility arrays
    uint8_t** decompressed;
    uint32_t* decomprOutputSize;
    // Scatter utility arrays
    std::vector<ScatterGather::Schema> scatter_schemas;
    //std::vector<std::vector<uint8_t>> gather_outs(kNofIterations, std::vector<uint8_t>(BUFFER_SIZE, 0));
    std::vector<std::vector<uint8_t>> gather_outs;
    // De/Serialization utility arrays
    std::vector<std::string> ser_outs;
    std::vector<M> deser_messages_out;
public:
    RequestSim(size_t MAX_REQUESTS=100, size_t BUFFER_SIZE=4096, size_t SCHEMA_LENGTH=256, IAAComp* iaa=nullptr, qpl_path_t path=qpl_path_software);
    ~RequestSim();
    int proto_ser_request(int);
    int proto_deser_request(int);
    int tachidromos_ser_request(int);
    int tachidromos_deser_request(int);
    void verify_correctness();
    void report_timings(std::vector<std::chrono::nanoseconds> perfs, std::string stat);
    void report();
};

#endif // SER_H