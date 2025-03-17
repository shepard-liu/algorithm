// https://leetcode.cn/problems/symmetric-tree/ Symmetric Tree
#include <stack>
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

bool isSymmetric(TreeNode *root) {
    stack<TreeNode *> left;
    stack<TreeNode *> right;

    left.push(root->left);
    right.push(root->right);

    while (!left.empty() && !right.empty()) {
        auto l = left.top();
        auto r = right.top();
        left.pop();
        right.pop();
        if ((l == nullptr) != (r == nullptr)) {
            return false;
        }
        if (l == nullptr && r == nullptr) {
            continue;
        }
        if (l->val != r->val) {
            return false;
        }

        left.push(l->left);
        left.push(l->right);
        right.push(r->right);
        right.push(r->left);
    }

    return left.empty() && right.empty();
}