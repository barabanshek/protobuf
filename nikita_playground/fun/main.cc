#include <google/protobuf/util/message_differencer.h>

#include <fstream>
#include <iostream>
#include <string>

#include "person.pb.h"

static constexpr size_t kNofIterations = 10000;
static constexpr size_t kNofWarmUpIterations = 100;

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  std::vector<Person> persons;
  std::vector<std::string> outs;
  for (size_t i = 0; i < kNofIterations; ++i) {
    Person person;
    // <------------ SETTERS ------>

    persons.push_back(person);
    outs.push_back("");
  }

  //
  // Benchmark serialize.
  //
  // Warm-up.
  for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
    if (!persons[i].SerializeToString(&outs[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }

  std::chrono::steady_clock::time_point begin =
      std::chrono::steady_clock::now();
  for (size_t i = kNofWarmUpIterations; i < persons.size(); ++i) {
    if (!persons[i].SerializeToString(&outs[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  auto took_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
  std::cout << "serialize took = "
            << took_ns / (persons.size() - kNofWarmUpIterations)
            << " [ns], size = " << outs[0].size() << " Bytes" << std::endl;

  //
  // Benchmark deserialize.
  //
  std::vector<Person> persons_out;
  for (size_t i = 0; i < persons.size(); ++i) persons_out.push_back(Person());

  // Warm-up.
  for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
    if (!persons_out[i].ParseFromString(outs[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }

  begin = std::chrono::steady_clock::now();
  for (size_t i = kNofWarmUpIterations; i < persons.size(); ++i) {
    if (!persons_out[i].ParseFromString(outs[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }
  end = std::chrono::steady_clock::now();
  took_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
  std::cout << "deserialize took = "
            << took_ns / (persons.size() - kNofWarmUpIterations)
            << " [ns], size = " << outs[0].size() << " Bytes" << std::endl;

  // Compare.
  bool all_correct = true;
  for (size_t i = 0; i < persons.size() && all_correct; ++i)
    all_correct = google::protobuf::util::MessageDifferencer::Equals(
        persons[i], persons_out[i]);
  std::cout << (all_correct ? "ALL CORRECT" : "ERROR: DATA MISSMATCH")
            << std::endl;

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
