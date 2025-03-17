#include "108_convert_sorted_array_to_binary_search_tree.hpp"

#include <gtest/gtest.h>

#include <vector>

#include "../test_utils.hpp"
typedef std::vector<int> TestCase;

void inorderTraverse(TreeNode* root, vector<int>& res) {
    if (root == nullptr) {
        return;
    }

    inorderTraverse(root->left, res);
    res.push_back(root->val);
    inorderTraverse(root->right, res);
}

void test_convert_sorted_array_to_binary_search_tree(TestCase& c) {
    auto nums = c;
    auto tree = sortedArrayToBST(nums);
    vector<int> myAns;
    inorderTraverse(tree, myAns);
    EXPECT_EQ(myAns, nums);
}

TEST(leetcode, convert_sorted_array_to_binary_search_tree) {
    std::vector<TestCase> cases{{1, 2, 3, 4, 5, 6}, {1, 2, 3, 4}};

    for (TestCase& c : cases) {
        test_convert_sorted_array_to_binary_search_tree(c);
    }
}
