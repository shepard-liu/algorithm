#include "46_permutations.hpp"

#include <iostream>
#include <vector>

#include "../test_utils.hpp"
typedef int TestCase;

TEST(leetcode, permutations) {
    vector<int> nums{1, 2, 3};
    std::cout << permute(nums) << std::endl;
}
