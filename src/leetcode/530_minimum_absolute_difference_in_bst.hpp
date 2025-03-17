// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/ Minimum
// Absolute Difference in BST
#include <algorithm>
#include <cmath>
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

inline void inorderTraverse(TreeNode *root, std::vector<int> &vals) {
    if (root == nullptr) {
        return;
    }

    inorderTraverse(root->left, vals);
    vals.push_back(root->val);
    inorderTraverse(root->right, vals);
}

inline int getMinimumDifference(TreeNode *root) {
    std::vector<int> vals{};
    inorderTraverse(root, vals);
    int minDiff{std::numeric_limits<int>::max()};
    for (int i = 1; i < vals.size(); ++i) {
        minDiff = std::min(std::abs(vals[i] - vals[i - 1]), minDiff);
    }
    return minDiff;
}