#include "105_construct_binary_tree_from_preorder_and_inorder_traversal.hpp"

#include <gtest/gtest.h>

#include <vector>

#include "../test_utils.hpp"

typedef TreeNode* TestCase;

void inorderTraverse(TreeNode* t, std::vector<int>& res) {
    if (t == nullptr) {
        return;
    }
    inorderTraverse(t->left, res);
    res.push_back(t->val);
    inorderTraverse(t->right, res);
}

void preorderTraverse(TreeNode* t, std::vector<int>& res) {
    if (t == nullptr) {
        return;
    }
    res.push_back(t->val);
    preorderTraverse(t->left, res);
    preorderTraverse(t->right, res);
}

void test_construct_binary_tree_from_preorder_and_inorder_traversal(
    TestCase& c) {
    std::vector<int> preorder;
    preorderTraverse(c, preorder);
    std::vector<int> inorder;
    inorderTraverse(c, inorder);

    auto constructed = buildTree(preorder, inorder);
    std::vector<int> myPreorder;
    std::vector<int> myInorder;
    preorderTraverse(constructed, myPreorder);
    inorderTraverse(constructed, myInorder);

    EXPECT_EQ(preorder, myPreorder);
    EXPECT_EQ(inorder, myInorder);
}

TEST(leetcode, construct_binary_tree_from_preorder_and_inorder_traversal) {
    TreeNode* t1 =
        new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(5)),
                     new TreeNode(10, new TreeNode(12),
                                  new TreeNode(6, nullptr, new TreeNode(19))));

    std::vector<TestCase> cases{t1};

    for (TestCase& c : cases) {
        test_construct_binary_tree_from_preorder_and_inorder_traversal(c);
    }
}
