#include "189_rotate_array.hpp"

#include <algorithm>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<std::vector<int>, int> TestCase;

void test_rotate_array(TestCase& c) {
    std::vector<int> nums = c.first;
    int k = c.second;
    std::vector<int> expected_nums = nums;
    std::rotate(expected_nums.rbegin(),
                expected_nums.rbegin() + k % nums.size(), expected_nums.rend());

    rotate(nums, k);

    ASSERT_EQ(nums, expected_nums);
}

TEST(leetcode, rotate_array) {
    std::vector<TestCase> cases{{{1, 2, 3, 4, 5, 6, 7}, 3},
                                {{-1, -100, 3, 99}, 2},
                                {{1, 2, 3, 4, 5, 6}, 4},
                                {{1, 2, 3}, 1},
                                {{1}, 0}};

    for (TestCase& c : cases) {
        test_rotate_array(c);
    }
}
