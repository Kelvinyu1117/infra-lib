#pragma once
#include <array>
#include <cassert>
#include <cctype>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <vector>
namespace container {

class Trie {
  struct TrieNode {
    TrieNode *_parent{nullptr};
    char key{};
    std::unordered_map<char, std::unique_ptr<TrieNode>> _slots{};
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

      node->_hasChildren = true;
      if (node->_slots.find(c) == node->_slots.end()) {
        node->_slots[c] = std::make_unique<TrieNode>();
      }

      node->_slots[c]->_parent = node;
      node = node->_slots[c].get();
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
    auto cursor = search_impl(s);
    return cursor != nullptr;
  }

  /**
   * @brief
   * Remove a word in the Trie, return true if it can be deleted
   * @param s
   * @return true
   * @return false
   */
  bool remove(const std::string &s) {
    auto cursor = search_impl(s);
    if (!cursor)
      return false;

    if (cursor->_hasChildren)
      cursor->_isWord = false;
    else {
      char key = cursor->key;
      cursor = cursor->_parent;

      while (cursor) {
        auto it = cursor->_slots.find(key);
        assert(it != cursor->_slots.end());

        it->second.reset();

        key = cursor->key;
        cursor = cursor->_parent;
      }
    }

    return true;
  }

private:
  TrieNode *search_impl(const std::string &s) {
    TrieNode *node = &_root;

    for (auto c : s) {

      auto it = node->_slots.find(c);

      if (it == node->_slots.end())
        return nullptr;

      node = it->second.get();
    }

    if (!node->_isWord)
      return nullptr;
    else
      return node;
  }

private:
  TrieNode _root;
};
} // namespace container
