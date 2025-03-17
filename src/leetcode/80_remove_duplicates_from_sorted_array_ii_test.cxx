#include "80_remove_duplicates_from_sorted_array_ii.hpp"

#include <vector>

#include "gtest/gtest.h"

typedef std::vector<int> TestCase;

void test_remove_duplicates_from_sorted_array_ii(TestCase& c) {
    std::vector<int> nums = c;
    std::vector<int> expected_nums;
    int count = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (i < 2 || nums[i] != nums[i - 2]) {
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

TEST(leetcode, remove_duplicates_from_sorted_array_ii) {
    std::vector<TestCase> cases{{1, 1, 1, 2, 2, 3},
                                {0, 0, 8, 1, 1, 1, 1, 2, 3, 3}};

    for (TestCase& c : cases) {
        test_remove_duplicates_from_sorted_array_ii(c);
    }
}
