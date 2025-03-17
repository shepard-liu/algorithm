// https://leetcode.cn/problems/sum-root-to-leaf-numbers/ Sum Root to Leaf
// Numbers
#include <iostream>
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

inline void sumNumbersImpl(TreeNode *root, int &sum, int cur) {
    cur = cur * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr) {
        sum += cur;
        std::cout << "cur = " << cur << std::endl;
    }
    if (root->left) {
        sumNumbersImpl(root->left, sum, cur);
    }
    if (root->right) {
        sumNumbersImpl(root->right, sum, cur);
    }
}

inline int sumNumbers(TreeNode *root) {
    int sum{0};
    sumNumbersImpl(root, sum, 0);
    return sum;
}