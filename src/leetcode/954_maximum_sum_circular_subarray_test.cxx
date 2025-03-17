#include "954_maximum_sum_circular_subarray.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<vector<int>, int> TestCase;

void test_maximum_sum_circular_subarray(TestCase& c) {
    auto [nums, ans] = c;
    auto myAns = maxSubarraySumCircular(nums);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, maximum_sum_circular_subarray) {
    std::vector<TestCase> cases{{{1, -2, 3, -2}, 3},
                                {{5, -3, 5}, 10},
                                {{3, -2, 2, -3}, 3},
                                {{3, 1, 3, 2, 6}, 15}};

    for (TestCase& c : cases) {
        test_maximum_sum_circular_subarray(c);
    }
}
