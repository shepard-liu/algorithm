// https://leetcode.cn/problems/invert-binary-tree/ Invert Binary Tree
#include <string>
#include <type_traits>
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

TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
        return root;
    }
    invertTree(root->left);
    invertTree(root->right);
    std::swap(root->left, root->right);
    return root;
}