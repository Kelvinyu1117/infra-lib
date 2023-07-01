#pragma once
#include <array>
#include <cstddef>
#include <memory>
#include <utility>
#include <vector>

namespace container {
template <typename T> class StableVector {
  struct Bucket {
    static constexpr size_t SIZE = 64;
    std::array<T, SIZE> chunk;
  };

  constexpr static size_t PREALLOCATE_SIZE = 8;

  using ThisType = StableVector<T>;

public:
  StableVector() : buckets(PREALLOCATE_SIZE) {
    for (size_t i = 0; i < PREALLOCATE_SIZE; i++) {
      buckets[i].emplace_back(std::make_unique<Bucket>());
    }
  }

  StableVector(size_t size) {
    size_t num_of_buckets =
        std::max(PREALLOCATE_SIZE, 1 + ((size - 1) / Bucket::SIZE));
    buckets.reserve(num_of_buckets);

    for (size_t i = 0; i < num_of_buckets; i++) {
      buckets[i].emplace_back(std::make_unique<Bucket>());
    }
  }

  StableVector(const ThisType &that) {}

  StableVector(ThisType &&that) noexcept {}

  ThisType &operator=(const ThisType &that) {}

  ThisType &operator=(ThisType &that) {}

  T &operator[](size_t i) {}

  const T &operator[](size_t i) const {}

  void push_back(const T &item) {}

  T &pop_back() {}

private:
  std::vector<std::unique_ptr<Bucket>> buckets;
};
} // namespace container
