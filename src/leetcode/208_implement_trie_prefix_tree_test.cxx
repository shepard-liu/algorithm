#include "208_implement_trie_prefix_tree.hpp"

#include <vector>

#include "../test_utils.hpp"
typedef int TestCase;

TEST(leetcode, implement_trie_prefix_tree) {
    Trie t;
    t.insert("apple");
    std::cout << "apple: " << t.search("apple") << std::endl;
}
