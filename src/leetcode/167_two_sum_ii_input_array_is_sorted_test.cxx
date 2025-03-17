#include "167_two_sum_ii_input_array_is_sorted.hpp"

#include <gtest/gtest.h>

#include <cstddef>
#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<std::vector<int>, int> TestCase;

void test_two_sum_ii_input_array_is_sorted(TestCase& c) {
    auto [arr, target] = c;
    std::cout << arr << "; Target: " << target << std::endl;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            if (j == i) {
                continue;
            }
            if (arr[i] + arr[j] == target) {
                if (i > j) {
                    std::swap(i, j);
                }
                std::cout << "answer: " << i << ", " << j << std::endl;
                EXPECT_EQ(std::vector({i, j}), twoSum(arr, target));
                return;
            }
        }
    }
}

TEST(leetcode, two_sum_ii_input_array_is_sorted) {
    std::vector<TestCase> cases{
        {{2, 7, 11, 15}, 9}, {{2, 3, 4}, 6}, {{-1, 0}, -1}};

    for (TestCase& c : cases) {
        test_two_sum_ii_input_array_is_sorted(c);
    }
}
