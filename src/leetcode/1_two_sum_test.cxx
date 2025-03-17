#include "1_two_sum.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<vector<int>, int> TestCase;

void test_two_sum(TestCase& c) {
    auto [arr, target] = c;

    vector<int> ans;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] + arr[j] == target) {
                ans = {i, j};
            }
        }
    }

    auto myAns = twoSum(arr, target);
    std::sort(myAns.begin(), myAns.end());
    EXPECT_EQ(ans, myAns);
}

TEST(leetcode, two_sum) {
    std::vector<TestCase> cases{
        {{2, 7, 11, 15}, 9}, {{3, 2, 4}, 6}, {{3, 3}, 6}};

    for (TestCase& c : cases) {
        test_two_sum(c);
    }
}
