#ifndef _DSA_1_H_
#define _DSA_1_H_

#include <accfg/idxd.h>
#include <accfg/libaccel_config.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/user.h>
#include <unistd.h>

#include <cassert>
#include <iostream>
#include <vector>

class Dsa {
 public:
  enum Path { Shared, Dedicated };

  Dsa(Path path) : path_(path) {}
  ~Dsa() { DeInit(); }

  int Init() {
    if (accfg_new(&ctx_)) return -1;

    if (SetupWq()) return -1;

    assert(wqs_.size() > 0);
    assert(wq_regs_.size() > 0);
    assert(fds_.size() > 0);

    return 0;
  }

  size_t GetNumOfWQs() const { return wqs_.size(); }

  void* GetWqRegister(size_t i) const { return wq_regs_[i]; }

  Path GetPath() const { return path_; }

  size_t GetBatchSize() const {
    if (wqs_.size() == 0) return 0;
    return accfg_wq_get_max_batch_size(wqs_[0]);
  }

  bool IsReady() const { return wq_regs_.size() > 0; }

  static inline void movdir64b(volatile void* portal, void* desc) {
    asm volatile(
        "sfence\t\n"
        ".byte 0x66, 0x0f, 0x38, 0xf8, 0x02\t\n"
        :
        : "a"(portal), "d"(desc));
  }

  static inline unsigned char enqcmd(volatile void* portal, void* desc) {
    unsigned char retry;
    asm volatile(
        "sfence\t\n"
        ".byte 0xf2, 0x0f, 0x38, 0xf8, 0x02\t\n"
        "setz %0\t\n"
        : "=r"(retry)
        : "a"(portal), "d"(desc));
    return retry;
  }

 private:
  int SetupWq() {
    accfg_device* device;
    accfg_wq* wq;

    accfg_device_foreach(ctx_, device) {
      // Make sure that the device is enabled
      if (accfg_device_get_state(device) != ACCFG_DEVICE_ENABLED) continue;

      accfg_wq_foreach(device, wq) {
        // Make sure iaa_test will not use dsa wq, vice versa
        if (accfg_device_get_type(device) != ACCFG_DEVICE_DSA) continue;

        // Get a workqueue that's enabled
        if (accfg_wq_get_state(wq) != ACCFG_WQ_ENABLED) continue;

        // The wq type should be user
        if (accfg_wq_get_type(wq) != ACCFG_WQT_USER) continue;

        // Make sure the mode is correct
        accfg_wq_mode mode = accfg_wq_get_mode(wq);
        if ((mode == ACCFG_WQ_SHARED && path_ == Dedicated) ||
            (mode == ACCFG_WQ_DEDICATED && path_ == Shared))
          continue;

        if (SetupWqRegister(wq)) return -1;

        wqs_.push_back(wq);
      }
    }

    return wqs_.size() == 0;
  }

  int SetupWqRegister(accfg_wq* wq) {
    char path[PATH_MAX];

    if (accfg_wq_get_user_dev_path(wq, path, PATH_MAX)) {
      std::cerr << "Error getting uacce device path" << std::endl;
      return -1;
    }

    int fd_ = open(path, O_RDWR);
    if (fd_ < 0) {
      std::cerr << "Error opening WQ file" << std::endl;
      return -1;
    }

    void* wq_reg =
        mmap(NULL, PAGE_SIZE, PROT_WRITE, MAP_SHARED | MAP_POPULATE, fd_, 0);
    if (wq_reg == MAP_FAILED) {
      std::cerr << "Error mapping WQ file" << std::endl;
      close(fd_);
      return -1;
    }

    wq_regs_.push_back(wq_reg);
    fds_.push_back(fd_);
    return 0;
  }

  void DeInit() {
    for (auto& wq_reg : wq_regs_) munmap(wq_reg, PAGE_SIZE);
    wq_regs_.clear();
    for (auto& fd : fds_) close(fd);
    fds_.clear();
    accfg_unref(ctx_);
  }

  //
  Path path_;

  //
  accfg_ctx* ctx_;
  std::vector<accfg_wq*> wqs_;
  std::vector<void*> wq_regs_;
  std::vector<int> fds_;
};

#endif
