#ifndef _SCATTER_GATHER_H_
#define _SCATTER_GATHER_H_

#include <cassert>
#include <cstring>
#include <iostream>
#include <tuple>
#include <vector>

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

class ScatterGather {
 public:
  // [<addr, size>]
  typedef std::vector<std::tuple<const uint8_t*, size_t>> Schema;

  int GatherWithMemCpy(const Schema& schema, uint8_t* out, size_t* out_size) {
    size_t out_offset = 0;
    for (const auto& el : schema) {
      memcpy(out + out_offset, std::get<0>(el), std::get<1>(el));
      out_offset += std::get<1>(el);
    }
    *out_size = out_offset;
    return 0;
  }

  int ScatterWithMemCpy(const uint8_t* in, const Schema& schema) {
    size_t in_offset = 0;
    for (const auto& el : schema) {
      memcpy(const_cast<uint8_t*>(std::get<0>(el)), in + in_offset,
             std::get<1>(el));
      in_offset += std::get<1>(el);
    }
    return 0;
  }

};

#endif
