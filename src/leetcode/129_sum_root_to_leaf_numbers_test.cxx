#include "129_sum_root_to_leaf_numbers.hpp"

#include <iostream>
#include <vector>

#include "../test_utils.hpp"
typedef TreeNode* TestCase;

void test_sum_root_to_leaf_numbers(TestCase& c) {
    int sum = sumNumbers(c);
    std::cout << sum << std::endl;
}

TEST(leetcode, sum_root_to_leaf_numbers) {
    TreeNode* t1 = new TreeNode(
        4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    std::vector<TestCase> cases{t1};

    for (TestCase& c : cases) {
        test_sum_root_to_leaf_numbers(c);
    }
}
