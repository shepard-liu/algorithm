#include "209_minimum_size_subarray_sum.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::tuple<std::vector<int>, int, int> TestCase;

void test_minimum_size_subarray_sum(TestCase& c) {
    auto [arr, target, ans] = c;
    auto myAns = minSubArrayLen(target, arr);
    std::cout << "Array: " << arr << "; Target: " << target << std::endl;
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, minimum_size_subarray_sum) {
    std::vector<TestCase> cases{{{2, 3, 1, 1, 1, 1, 1}, 5, 2},
                                {{2, 3, 1, 2, 4, 3}, 7, 2},
                                {{1, 4, 4}, 4, 1},
                                {{1, 1, 1, 1, 1, 1, 1, 1}, 11, 0},
                                {{1, 2, 3, 4, 5}, 11, 3},
                                {{5, 1, 3, 5, 10, 7, 4, 9, 2, 8}, 15, 2}};

    for (TestCase& c : cases) {
        test_minimum_size_subarray_sum(c);
    }
}
