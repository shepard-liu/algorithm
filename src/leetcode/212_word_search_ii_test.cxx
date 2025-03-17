#include "212_word_search_ii.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "../test_utils.hpp"
typedef tuple<vector<vector<char>>, vector<string>, vector<string>> TestCase;

void test_word_search_ii(TestCase& c) {
    auto [board, words, ans] = c;
    auto myAns = findWords(board, words);
    sort(myAns.begin(), myAns.end());
    sort(ans.begin(), ans.end());
    EXPECT_EQ(ans, myAns);
}

TEST(leetcode, word_search_ii) {
    TestCase c1{{{'o', 'a', 'a', 'n'},
                 {'e', 't', 'a', 'e'},
                 {'i', 'h', 'k', 'r'},
                 {'i', 'f', 'l', 'v'}},
                {"oath", "pea", "eat", "rain"},
                {"eat", "oath"}};

    TestCase c2{{{'a', 'b'}, {'c', 'd'}}, {"abcb"}, {}};

    TestCase c3{{{'b', 'b', 'a', 'a', 'b', 'a'},
                 {'b', 'b', 'a', 'b', 'a', 'a'},
                 {'b', 'b', 'b', 'b', 'b', 'b'},
                 {'a', 'a', 'a', 'b', 'a', 'a'},
                 {'a', 'b', 'a', 'a', 'b', 'b'}},
                {"abbbababaa"},
                {}};
    std::vector<TestCase> cases{c3, c2, c1};

    for (TestCase& c : cases) {
        test_word_search_ii(c);
    }
}
