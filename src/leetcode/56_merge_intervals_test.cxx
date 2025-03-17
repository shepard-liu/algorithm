#include "56_merge_intervals.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef pair<vector<vector<int>>, vector<vector<int>>> TestCase;

void test_merge_intervals(TestCase& c) {
    auto [input, ans] = c;
    auto myAns = merge(input);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, merge_intervals) {
    std::vector<TestCase> cases{
        {{{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}},
        {{{1, 4}, {4, 5}}, {{1, 5}}}};

    for (TestCase& c : cases) {
        test_merge_intervals(c);
    }
}
