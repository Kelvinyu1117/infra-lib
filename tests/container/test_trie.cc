#include <container/trie.hpp>
#include <gtest/gtest.h>

TEST(Trie, DefaultConstruction) {
  using namespace container;
  Trie t{};

  EXPECT_EQ(t.search("hello"), false);

  t.insert("hello");

  EXPECT_EQ(t.search("hello"), true);
}
