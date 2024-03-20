#include "scatter_gather.h"

#include <iostream>
#include <vector>

static constexpr size_t N = 8;
static constexpr size_t M = 1024;

int main() {
  // Data.
  std::vector<std::vector<uint8_t>> scattered;
  scattered.reserve(N);
  for (size_t i = 0; i < N; ++i) {
    scattered.push_back(std::vector<uint8_t>());
    scattered.back().reserve(M);
    for (size_t j = 0; j < M; ++j) scattered.back().push_back(i + j);
  }

  // ScatterGather'er.
  ScatterGather stuff(Dsa::Shared, N);
  if (stuff.Init()) {
    std::cout << "Error" << std::endl;
    return -1;
  }
  std::cout << "ScatterGather is initialized and ready" << std::endl;

  //
  // Do Scatter.
  //
  std::vector<uint8_t> out(N * M, 0);
  // <-------------- time start
  ScatterGather::Schema schema;
  schema.reserve(N);
  for (const auto& el : scattered) {
    schema.push_back(std::make_tuple(el.data(), el.size()));
  }
  size_t out_size = 0;
  if (stuff.Gather(schema, out.data(), &out_size)) {
    std::cout << "Failed to gather" << std::endl;
    return -1;
  }
  assert(out.size() == out_size);
  // -----------------> time stop

  std::cout << "Gather done, out_size= " << out_size << " Bytes" << std::endl;

  //
  // Do Gather.
  //
  ScatterGather::Schema schema_gather;
  std::vector<std::vector<uint8_t>> scattered_out;
  scattered_out.reserve(N);
  for (size_t i = 0; i < N; ++i) {
    scattered_out.push_back(std::vector<uint8_t>(M, 1));
    schema_gather.push_back(std::make_tuple(scattered_out.back().data(),
                                            scattered_out.back().size()));
  }

  // <-------------- time start
  if (stuff.Scatter(out.data(), schema_gather)) {
    std::cout << "Failed to scatter" << std::endl;
    return -1;
  }
  // -----------------> time stop

  std::cout << "Scatter done" << std::endl;

  //
  // Verify.
  //
  bool correct = true;
  for (size_t i = 0; i < N && correct; ++i) {
    for (size_t j = 0; j < M && correct; ++j) {
      if (scattered_out[i][j] != scattered[i][j]) correct = false;
    }
  }
  std::cout << (correct ? "ALL GOOD" : "DATA MISSMATCH") << std::endl;

  return 0;
}
