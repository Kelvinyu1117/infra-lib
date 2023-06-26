#pragma once
#include <array>
#include <cstddef>
#include <memory>
#include <vector>
namespace container {

class Trie {
  class TrieNode {
    std::array<std::unique_ptr<TrieNode>, 26> _slots;
    bool _isWord{false};
    bool _hasChildren{false};
  };

public:
  Trie(std::vector<std::string> &words) {}

  /**
   * @brief
   *  Insert a string into the Trie, return true if the Trie does not contain
   * the word the word
   * @param s
   * @return true
   * @return false
   */
  bool insert(const std::string &s) { return false; }

  /**
   * @brief
   * Search for a word in the Trie, return true if the word is found
   * @param s
   * @return true
   * @return false
   */
  bool search(const std::string &s) { return false; }

  /**
   * @brief
   * Remove a word in the Trie, return true if it can be deleted
   * @param s
   * @return true
   * @return false
   */
  bool remove(const std::string &s) { return false; }

private:
  TrieNode root;
};
} // namespace container
