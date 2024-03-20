#include <google/protobuf/util/message_differencer.h>

#include <fstream>
#include <iostream>
#include <string>

#include "iaa_comp.h"
#include "person.pb.h"

#define BUFFER_SIZE 4096

static constexpr size_t kNofIterations = 10000;
static constexpr size_t kNofWarmUpIterations = 100;

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  // initialize iaa jobs
	iaa_init_jobs(qpl_path_hardware);

  std::vector<M> messages;
  // arrays for keeping the buffering the intermediate outputs of IAA
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

    messages.push_back(m);
  }

  //
  // Benchmark serialize.
  //
  // Warm-up.
 
  /* COMPRESSION WITH IAA COMMANDS
	uint8_t* ogByteStream = reinterpret_cast<uint8_t*>(&messages[i]);
	compress_with_IAA(ogByteStream, sizeof(messages[i]), compressed[i], BUFFER_SIZE, &comprOutputSize[i]);
	decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i]);
  */

  for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
    //if (!messages[i].SerializeToString(&outs[i])) {
    uint8_t* ogByteStream = reinterpret_cast<uint8_t*>(&messages[i]);
    if (compress_with_IAA(ogByteStream, sizeof(messages[i]), compressed[i], BUFFER_SIZE, &comprOutputSize[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }

  std::chrono::steady_clock::time_point begin =
      std::chrono::steady_clock::now();
  for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
    //if (!messages[i].SerializeToString(&outs[i])) {
    uint8_t* ogByteStream = reinterpret_cast<uint8_t*>(&messages[i]);
    if (compress_with_IAA(ogByteStream, sizeof(messages[i]), compressed[i], BUFFER_SIZE, &comprOutputSize[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  auto took_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
  std::cout << "serialize took = "
            << took_ns / (messages.size() - kNofWarmUpIterations)
            << " [ns], size = " << comprOutputSize[0] << " Bytes" << std::endl;

  //
  // Benchmark deserialize.
  //
  std::vector<M> messages_out;
  for (size_t i = 0; i < messages.size(); ++i) messages_out.push_back(M());

  // Warm-up.
  for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
    //if (!messages_out[i].ParseFromString(outs[i])) {
    if (decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }

  begin = std::chrono::steady_clock::now();
  for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
    //if (!messages_out[i].ParseFromString(outs[i])) {
    if (decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }
  end = std::chrono::steady_clock::now();
  took_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
  std::cout << "deserialize took = "
            << took_ns / (messages.size() - kNofWarmUpIterations)
            << " [ns], size = " << decomprOutputSize[0] << " Bytes" << std::endl;

  // Compare.
  /*
  bool all_correct = true;
  for (size_t i = 0; i < messages.size() && all_correct; ++i)
    all_correct = google::protobuf::util::MessageDifferencer::Equals(
        messages[i], messages_out[i]);
  std::cout << (all_correct ? "ALL CORRECT" : "ERROR: DATA MISSMATCH")
            << std::endl;
  */

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  // free existing iaa jobs
	iaa_fini_jobs();

  return 0;
}
