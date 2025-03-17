// https://leetcode.cn/problems/same-tree/ Same Tree
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

bool isSameTree(TreeNode *p, TreeNode *q) {
    if ((p == nullptr) != (q == nullptr)) {
        return false;
    }
    if (p == nullptr && q == nullptr) {
        return true;
    }
    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}