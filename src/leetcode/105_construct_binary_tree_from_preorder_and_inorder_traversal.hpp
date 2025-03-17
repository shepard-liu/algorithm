// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Construct Binary Tree from Preorder and Inorder Traversal
#include <cstddef>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
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

inline bool withinRange(const std::pair<int, int> &range, int val) {
    return val >= range.first && val < range.second;
}

inline TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();

    unordered_map<int, int> inorderLookup;
    inorderLookup.reserve(n);

    for (int i = 0; i < n; ++i) {
        inorderLookup[inorder[i]] = i;
    }

    TreeNode *root = new TreeNode(preorder[0]);

    stack<std::pair<TreeNode *,
                    std::pair<std::pair<int, int>, std::pair<int, int>>>>
        path;
    {
        int rootInorderPos = inorderLookup[root->val];
        path.push({root, {{0, rootInorderPos}, {rootInorderPos + 1, n}}});
    }

    int i = 1;
    while (i < n) {
        // auto [leftRange, rightRange] = path.top().second;
        auto leftRange = path.top().second.first;
        auto rightRange = path.top().second.second;
        auto cur = path.top().first;
        int preVal = preorder[i];
        int inorderPos = inorderLookup[preVal];

        // number is in the left subtree of current root
        if (withinRange(leftRange, inorderPos)) {
            if (cur->left != nullptr) {
                cur = cur->left;
                int curInorderPos = inorderLookup[cur->val];
                path.push({cur,
                           {{leftRange.first, curInorderPos},
                            {curInorderPos + 1, leftRange.second}}});
            } else {
                cur->left = new TreeNode(preVal);
                i++;
            }
        } else if (withinRange(rightRange, inorderPos)) {
            if (cur->right != nullptr) {
                cur = cur->right;
                int curInorderPos = inorderLookup[cur->val];
                path.push({cur,
                           {{rightRange.first, curInorderPos},
                            {curInorderPos + 1, rightRange.second}}});
            } else {
                cur->right = new TreeNode(preVal);
                i++;
            }
            // neither in the left nor right
        } else {
            path.pop();
        }
    }

    return root;
}