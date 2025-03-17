#include "39_combination_sum.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

#include "../test_utils.hpp"
typedef tuple<vector<int>, int, vector<vector<int>>> TestCase;

void test_combination_sum(TestCase& c) {
    auto [can, tar, ans] = c;
    auto myAns = combinationSum(can, tar);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, combination_sum) {
    TestCase c1{{2, 3, 6, 7}, 7, {{2, 2, 3}, {7}}};
    std::vector<TestCase> cases{c1};

    for (TestCase& c : cases) {
        test_combination_sum(c);
    }
}
