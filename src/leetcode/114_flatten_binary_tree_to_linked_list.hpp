// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/ Flatten
// Binary Tree to Linked List
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

TreeNode *flattenImpl(TreeNode *node) {
    auto leftEnd = node->left == nullptr ? nullptr : flattenImpl(node->left);
    auto rightEnd = node->right == nullptr ? nullptr : flattenImpl(node->right);
    if (leftEnd != nullptr) {
        leftEnd->right = node->right;
        node->right = node->left;
    }
    node->left = nullptr;
    return rightEnd == nullptr ? leftEnd == nullptr ? node : leftEnd : rightEnd;
}

inline void flatten(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    flattenImpl(root);
}