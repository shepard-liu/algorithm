// https://leetcode.cn/problems/validate-binary-search-tree/ Validate Binary
// Search Tree
#include <cstdint>
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

inline bool inorderTraverse(TreeNode *root, int64_t &last) {
    if (root == nullptr) {
        return true;
    }

    bool isLeftValid = inorderTraverse(root->left, last);
    if (!isLeftValid) {
        return false;
    }

    if (last >= (int64_t)root->val) {
        return false;
    }
    last = (int64_t)root->val;

    bool isRightValid = inorderTraverse(root->right, last);
    return isRightValid;
}

inline int64_t IntMin = std::numeric_limits<int64_t>::min();

inline bool isValidBST(TreeNode *root) {
    int64_t last{IntMin};
    return inorderTraverse(root, last);
}