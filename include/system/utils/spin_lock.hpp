#pragma once
#include <atomic>
#include <emmintrin.h>
namespace sys::utils {

class SpinLock {
public:
  SpinLock() = default;
  SpinLock(const SpinLock &) = delete;
  SpinLock(SpinLock &&) = delete;
  SpinLock &operator=(const SpinLock &) = delete;
  SpinLock &operator=(SpinLock &&) = delete;

  void lock() {
    // test and test and set
    while (true) {
      if (lock_.test_and_set(std::memory_order_acquire)) {
        return;
      }

      while (lock_.test(std::memory_order_relaxed)) {
        _mm_pause();
      }
    }
  }

  void unlock() { lock_.clear(std::memory_order_release); }

private:
  std::atomic_flag lock_;
};
} // namespace sys::utils
