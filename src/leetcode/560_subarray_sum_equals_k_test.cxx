#include "560_subarray_sum_equals_k.hpp"

#include <iostream>
#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<vector<int>, int> TestCase;

void test_subarray_sum_equals_k(TestCase& c) {
    auto [nums, k] = c;
    auto myAns = subarraySum(nums, k);
    std::cout << "myAns: " << myAns << endl;
}

TEST(leetcode, subarray_sum_equals_k) {
    std::vector<TestCase> cases{
        {{100, 1, 2, 3, 4}, 3},
        {{-19, -82, -70, -46, -29, 7, 15, -72, -7, 100, 303}, 100},
        {{1, -1, 0}, {0}},
        {{1}, 0},
        {{1, 1, 1}, 2},
        {{1}, 1},
        {{1, -1, 3, 2, 4, 3, -2}, 5}};

    for (TestCase& c : cases) {
        test_subarray_sum_equals_k(c);
    }
}
