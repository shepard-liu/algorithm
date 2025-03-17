#include "128_longest_consecutive_sequence.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<vector<int>, int> TestCase;

void test_longest_consecutive_sequence(TestCase& c) {
    auto [arr, ans] = c;
    auto myAns = longestConsecutive(arr);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, longest_consecutive_sequence) {
    std::vector<TestCase> cases{{{100, 4, 200, 1, 3, 2}, 4},
                                {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},
                                {{1, 0, 1, 2}, 3}};

    for (TestCase& c : cases) {
        test_longest_consecutive_sequence(c);
    }
}
