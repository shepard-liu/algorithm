#include "106_construct_binary_tree_from_inorder_and_postorder_traversal.hpp"

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

void postorderTraverse(TreeNode* t, std::vector<int>& res) {
    if (t == nullptr) {
        return;
    }
    postorderTraverse(t->left, res);
    postorderTraverse(t->right, res);
    res.push_back(t->val);
}

void test_construct_binary_tree_from_inorder_and_postorder_traversal(
    TestCase& c) {
    std::vector<int> postorder;
    postorderTraverse(c, postorder);
    std::vector<int> inorder;
    inorderTraverse(c, inorder);

    std::cout << "postorder: " << postorder << "\ninorder:" << inorder
              << std::endl;

    auto constructed = buildTree(inorder, postorder);
    std::vector<int> myPostorder;
    std::vector<int> myInorder;
    postorderTraverse(constructed, myPostorder);
    inorderTraverse(constructed, myInorder);

    EXPECT_EQ(postorder, myPostorder);
    EXPECT_EQ(inorder, myInorder);
}

TEST(leetcode, construct_binary_tree_from_inorder_and_postorder_traversal) {
    TreeNode* t1 =
        new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(5)),
                     new TreeNode(10, new TreeNode(12),
                                  new TreeNode(6, nullptr, new TreeNode(19))));

    std::vector<TestCase> cases{t1};

    for (TestCase& c : cases) {
        test_construct_binary_tree_from_inorder_and_postorder_traversal(c);
    }
}
