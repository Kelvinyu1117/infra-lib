#pragma once
#include <array>
#include <cstddef>
#include <vector>

namespace container {
template <typename T> class stable_vector {
  struct Bucket {
    static constexpr size_t SIZE = sizeof(T) / 64;
    std::array<T, SIZE> chunk;
  };

private:
  std::vector<Bucket> buckets;
};
} // namespace container
