#include "26_remove_duplicates_from_sorted_array.hpp"

#include <cstddef>
#include <vector>

#include "gtest/gtest.h"

typedef vector<int> TestCase;

void test_remove_duplicates_from_sorted_array(const TestCase& c) {
    std::vector<int> nums = c;
    std::vector<int> expected_nums;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            expected_nums.push_back(nums[i]);
        }
    }
    int expected_length = expected_nums.size();

    int result_length = removeDuplicates(nums);

    ASSERT_EQ(result_length, expected_length);
    for (int i = 0; i < expected_length; ++i) {
        ASSERT_EQ(nums[i], expected_nums[i]);
    }
}

TEST(leetcode, remove_duplicates_from_sorted_array) {
    std::vector<TestCase> cases{{1, 1, 2},
                                {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
                                {1, 2, 3, 4, 5},
                                {1, 1, 1, 1, 1},
                                {}};

    for (TestCase& c : cases) {
        test_remove_duplicates_from_sorted_array(c);
    }
}
