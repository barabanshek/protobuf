#ifndef _SCATTER_GATHER_H_
#define _SCATTER_GATHER_H_

#include <accfg/idxd.h>
#include <accfg/libaccel_config.h>
#include <numa.h>
#include <numaif.h>
#include <x86intrin.h>

#include <cassert>
#include <chrono>
#include <cstring>
#include <iostream>
#include <tuple>
#include <vector>

#include "dsa.h"

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

__attribute__((always_inline)) inline void clflush(void* adrs) {
  asm __volatile__("clflush 0(%0)  \n" : : "r"(adrs) :);
}

class ScatterGather {
 public:
  // [<addr, size>]
  typedef std::vector<std::tuple<const uint8_t*, size_t>> Schema;

  ScatterGather(Dsa::Path path, size_t batch_size)
      : dsa(path), ready_(false), n_desc_(batch_size) {}

  void SetZero() {
    scatter_cnt_ = 0;
    scatter_took_ = 0;
  }
  size_t GetTime() const { return scatter_took_ / scatter_cnt_; }

  int Init() {
    if (numa_available() == -1) {
      std::cout << "No NUMA\n";
    }
    // Init DSA.
    if (dsa.Init()) return -1;

    size_t wqs_n = dsa.GetNumOfWQs();
    std::cout << "Number of WQs: " << wqs_n << std::endl;

    // Check number of supported descriptors.
    if (dsa.GetBatchSize() < n_desc_) {
      std::cout << "Too many descriptors requested in a batch" << std::endl;
      return -1;
    }

    // Init descriptor pool.
    desc_pool_ = reinterpret_cast<hw_desc*>(
        // aligned_alloc(PAGE_SIZE, sizeof(hw_desc) * n_desc_));
        numa_alloc_onnode(sizeof(hw_desc) * n_desc_, 1));
    if (desc_pool_ == nullptr) return -1;

    memset(desc_pool_, 0, sizeof(hw_desc) * n_desc_);

    // Pre-setup descriptors.
    for (size_t i = 0; i < n_desc_; ++i) {
      desc_pool_[i].flags =
          IDXD_OP_FLAG_CC;  // Don't generate individual completions, and do
                            // cache control.
      desc_pool_[i].opcode = DSA_OPCODE_NOOP;
    }

    // Init batch descriptors.
    size_t n_desc_in_batch = n_desc_ / wqs_n;
    for (size_t i = 0; i < wqs_n; ++i) {
      auto desc_batch =
          reinterpret_cast<hw_desc*>(aligned_alloc(64, sizeof(hw_desc)));
      if (desc_batch == nullptr) return -1;
      auto compl_batch = reinterpret_cast<completion_record*>(
          aligned_alloc(32, sizeof(completion_record)));
      if (compl_batch == nullptr) return -1;

      memset(desc_batch, 0, sizeof(hw_desc));
      memset(compl_batch, 0, sizeof(completion_record));

      desc_batch->completion_addr = reinterpret_cast<uint64_t>(compl_batch);
      desc_batch->flags =
          IDXD_OP_FLAG_CRAV | IDXD_OP_FLAG_RCR;  // Request final completion.
      desc_batch->opcode = DSA_OPCODE_BATCH;
      desc_batch->desc_list_addr =
          reinterpret_cast<uint64_t>(desc_pool_ + i * n_desc_in_batch);

      desc_batch_.push_back(desc_batch);
      compl_batch_.push_back(compl_batch);
    }

    ready_ = true;
    return 0;
  }

  int Gather(const Schema& schema, uint8_t* out, size_t* out_size,
             bool blocking = true) {
    if (unlikely(schema.size() > n_desc_)) return -1;

    assert(ready_);
    assert(blocking);  // TODO(Nikita): for now

    size_t d_i = 0;
    size_t out_offset = 0;
    for (const auto& el : schema) {
      desc_pool_[d_i].src_addr = reinterpret_cast<uint64_t>(std::get<0>(el));
      desc_pool_[d_i].dst_addr = reinterpret_cast<uint64_t>(out + out_offset);
      desc_pool_[d_i].xfer_size = std::get<1>(el);
      // demote(&desc_pool_[d_i]);
      out_offset += std::get<1>(el);
      ++d_i;
    }
    *out_size = out_offset;

    for (int i = 0; i < dsa.GetNumOfWQs(); ++i) {
      if (Submit(schema.size() / dsa.GetNumOfWQs(), i, false)) return -1;
    }

    // Wait.
    for (int i = 0; i < dsa.GetNumOfWQs(); ++i) {
      while (compl_batch_[i]->status == 0)
        ;
    }

    // Submit.
    // return Submit(schema.size(), blocking);
    return 0;
  }

  int GatherWithMemCpy(const Schema& schema, uint8_t* out, size_t* out_size) {
    size_t out_offset = 0;
    for (const auto& el : schema) {
      memcpy(out + out_offset, std::get<0>(el), std::get<1>(el));
      out_offset += std::get<1>(el);
    }
    *out_size = out_offset;
    return 0;
  }

  int Scatter(const uint8_t* in, const Schema& schema, bool blocking = true) {
    if (unlikely(schema.size() > n_desc_)) return -1;

    assert(ready_);
    assert(blocking);  // TODO(Nikita): for now

    size_t d_i = 0;
    size_t in_offset = 0;
    for (const auto& el : schema) {
      desc_pool_[d_i].src_addr = reinterpret_cast<uint64_t>(in + in_offset);
      desc_pool_[d_i].dst_addr = reinterpret_cast<uint64_t>(std::get<0>(el));
      desc_pool_[d_i].xfer_size = std::get<1>(el);
      in_offset += std::get<1>(el);
      ++d_i;
    }
    for (d_i = 0; d_i < schema.size(); ++d_i) {
      _cldemote(&desc_pool_[d_i]);
    }
    _mm_mfence();

    for (int i = 0; i < dsa.GetNumOfWQs(); ++i) {
      if (Submit(schema.size() / dsa.GetNumOfWQs(), i, false)) return -1;
    }

    auto begin = std::chrono::steady_clock::now();

    // Wait.
    for (int i = 0; i < dsa.GetNumOfWQs(); ++i) {
      while (compl_batch_[i]->status == 0)
        ;
    }

    auto end = std::chrono::steady_clock::now();
    scatter_took_ +=
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin)
            .count();
    ++scatter_cnt_;

    // Submit.
    // return Submit(schema.size(), blocking);
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

 private:
  inline int Submit(size_t n_desc, int wq_n, bool blocking = true) {
    compl_batch_[wq_n]->status = 0;

    desc_batch_[wq_n]->desc_count = n_desc;
    if (dsa.GetPath() == Dsa::Shared) {
      if (unlikely(Dsa::enqcmd(dsa.GetWqRegister(wq_n), desc_batch_[wq_n]))) {
        std::cout << "ERROR when submitting DSA job." << std::endl;
        return -1;
      }
    } else {
      Dsa::movdir64b(dsa.GetWqRegister(wq_n), desc_batch_[wq_n]);
    }

    // Wait.
    // if (blocking) {
    //   while (compl_batch_[wq_n]->status == 0)
    //     ;
    //   if (compl_batch_[wq_n]->status > 1) {
    //     std::cout << "Error processing descriptors: " << std::hex
    //               << static_cast<int>(compl_batch_[wq_n]->status) <<
    //               std::dec
    //               << std::endl;
    //     return -1;
    //   }
    // }

    return 0;
  }

  //
  Dsa dsa;
  bool ready_;

  //
  size_t n_desc_;
  hw_desc* desc_pool_;

  //
  std::vector<hw_desc*> desc_batch_;
  std::vector<completion_record*> compl_batch_;

  //
  size_t scatter_cnt_;
  size_t scatter_took_;
};

#endif
