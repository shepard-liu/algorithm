#include "117_populating_next_right_pointers_in_each_node_ii.hpp"

#include <vector>

#include "../test_utils.hpp"
typedef Trie* TestCase;

void test_populating_next_right_pointers_in_each_node_ii(TestCase& c) {
    connect(c);
}

TEST(leetcode, populating_next_right_pointers_in_each_node_ii) {
    Trie* t1 =
        new Trie(1, new Trie(3, nullptr, new Trie(5), nullptr),
                 new Trie(10, new Trie(12),
                          new Trie(6, nullptr, new Trie(19), nullptr), nullptr),
                 nullptr);

    std::vector<TestCase> cases{t1};

    for (TestCase& c : cases) {
        test_populating_next_right_pointers_in_each_node_ii(c);
    }
}
