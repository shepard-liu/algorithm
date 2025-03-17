// https://leetcode.cn/problems/count-complete-tree-nodes/ Count Complete Tree
// Nodes
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

inline int countNodes(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}