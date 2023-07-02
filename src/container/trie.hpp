#pragma once
#include <array>
#include <cctype>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <vector>
namespace container {

enum class TrieType { LOWER_CASE, UPPER_CASE };

template <TrieType T> class Trie {
  struct TrieNode {
    TrieNode *_parent{nullptr};
    std::array<std::unique_ptr<TrieNode>, 26> _slots{};
    bool _isWord{false};
    bool _hasChildren{false};
  };

public:
  Trie() = default;

  Trie(std::vector<std::string> &words) {
    for (const auto &word : words) {
      insert(word);
    }
  }

  /**
   * @brief
   * Insert a string into the Trie
   * @param word
   */
  void insert(const std::string &word) {
    TrieNode *node = &_root;
    for (auto c : word) {
      auto idx = getIndex(c);

      node->_hasChildren = true;
      if (!node->_slots[idx]) {
        node->_slots[idx] = std::make_unique<TrieNode>();
      }

      node->_slots[idx]->_parent = node;
      node = node->_slots[idx].get();
    }

    node->_isWord = true;
  }

  /**
   * @brief
   * Search for a word in the Trie, return true if the word is found
   * @param s
   * @return true
   * @return false
   */
  bool search(const std::string &s) {
    TrieNode *node = &_root;

    for (auto c : s) {
      auto idx = getIndex(c);
      auto next = node->_slots[idx].get();

      if (!next)
        return false;

      node = next;
    }

    return true;
  }

  /**
   * @brief
   * Remove a word in the Trie, return true if it can be deleted
   * @param s
   * @return true
   * @return false
   */
  bool remove(const std::string &s) {}

private:
  size_t getIndex(char c) {
    if (!isalpha(c))
      throw std::invalid_argument("The Trie only accept alphabetical letter.");

    int idx;
    if constexpr (T == TrieType::LOWER_CASE) {
      if (!islower(c))
        throw std::invalid_argument("The LOWER_TYPE Trie only accept lower "
                                    "case alphabetical letter.");

      return static_cast<int>(c) - static_cast<int>('a');
    } else {
      if (!isupper(c))
        throw std::invalid_argument("The UPPER_CASE Trie only accept lower "
                                    "case alphabetical letter.");
      return static_cast<int>(c) - static_cast<int>('A');
    }
  }

private:
  TrieNode _root;
};
} // namespace container
