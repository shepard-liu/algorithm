// https://leetcode.cn/problems/binary-tree-right-side-view/ Binary Tree Right
// Side View
#include <limits>
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

inline void rightSideImpl(TreeNode *root, std::vector<int> &vals, int level) {
    if (root == nullptr) {
        return;
    }
    if (vals.size() == level) {
        vals.push_back(root->val);
    }
    rightSideImpl(root->right, vals, level + 1);
    rightSideImpl(root->left, vals, level + 1);
}

inline vector<int> rightSideView(TreeNode *root) {
    std::vector<int> vals;
    rightSideImpl(root, vals, 0);
    return vals;
}