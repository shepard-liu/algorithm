// https://leetcode.cn/problems/binary-tree-maximum-path-sum/ Binary Tree
// Maximum Path Sum
#include <algorithm>
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

int IntMin = -1e5;

inline int maxPathSumImpl(TreeNode *root, int &maxSum) {
    int val = root->val;
    int myMax{};
    int ret{};
    if (root->left == nullptr && root->right == nullptr) {
        myMax = val;
        ret = val;
    } else {
        int leftMax =
            root->left == nullptr ? IntMin : maxPathSumImpl(root->left, maxSum);
        int rightMax = root->right == nullptr
                           ? IntMin
                           : maxPathSumImpl(root->right, maxSum);
        ret = std::max(std::max(leftMax + val, rightMax + val), val);
        myMax = std::max(ret, leftMax + rightMax + val);
    }
    if (myMax > maxSum) {
        maxSum = myMax;
    }
    return ret;
}

inline int maxPathSum(TreeNode *root) {
    int maxSum = IntMin;
    maxPathSumImpl(root, maxSum);
    return maxSum;
}