#include "27_remove_element.hpp"

#include <iostream>
#include <utility>
#include <vector>

#include "../test_utils.hpp"
#include "gtest/gtest.h"

typedef std::pair<vector<int>, int> TestCase;

void test_remove_element(TestCase& c) {
    std::vector<int>& nums = c.first;
    int val = c.second;
    int expected_length = std::count_if(nums.begin(), nums.end(),
                                        [val](int x) { return x != val; });
    std::cout << c.first << std::endl;
    int result_length = removeElement(nums, val);
    std::cout << c.first << std::endl;

    EXPECT_EQ(result_length, expected_length);

    for (int i = 0; i < result_length; ++i) {
        EXPECT_NE(nums[i], val);
    }
}

TEST(leetcode, remove_element) {
    std::vector<TestCase> cases{
        {{3, 2, 2, 3}, 3}, {{}, 0}, {{1}, 0}, {{0, 1, 2, 2, 3, 0, 4, 2}, 2}};

    for (TestCase& c : cases) {
        test_remove_element(c);
    }
}
