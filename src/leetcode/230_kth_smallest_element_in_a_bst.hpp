// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/ Kth Smallest
// Element in a BST
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

int Signal = -1;

inline int inorderTraverse(TreeNode *root, int &k) {
    if (root == nullptr) {
        return Signal;
    }

    int leftVal = inorderTraverse(root->left, k);

    if (leftVal != Signal) {
        return leftVal;
    }

    k--;
    if (k == 0) {
        return root->val;
    }

    int rightVal = inorderTraverse(root->right, k);

    return rightVal;
}

inline int kthSmallest(TreeNode *root, int k) {
    return inorderTraverse(root, k);
}