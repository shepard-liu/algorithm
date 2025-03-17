// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/ Lowest
// Common Ancestor of a Binary Tree
#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

inline void copyPrint(const std::stack<TreeNode*>& s) {
    auto copy = s;
    std::vector<int> nums;
    while (!copy.empty()) {
        nums.push_back(copy.top()->val);
        copy.pop();
    }

    std::reverse(nums.begin(), nums.end());

    for (auto n : nums) {
        if (n != nums.back()) {
            std::cout << n << " -> ";
        } else {
            std::cout << n;
        }
    }
    std::cout << std::endl;
}

inline void recurse(TreeNode* root, TreeNode** p, TreeNode** q,
                    std::vector<TreeNode*>& path,
                    std::function<void(TreeNode* node)> onFound) {
    if (root == nullptr) {
        return;
    }

    path.push_back(root);

    if (root == *p || root == *q) {
        onFound(root);
    }

    recurse(root->left, p, q, path, onFound);
    recurse(root->right, p, q, path, onFound);
    path.erase(path.end() - 1);
}

inline TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,
                                      TreeNode* q) {
    std::vector<TreeNode*> path;
    std::vector<TreeNode*> path1;
    std::vector<TreeNode*> path2;

    recurse(root, &p, &q, path, [&](TreeNode* node) {
        if (path1.empty()) {
            path1 = path;
            if (node == p) {
                p = nullptr;
            } else {
                q = nullptr;
            }
        } else {
            path2 = path;
        }
    });

    for (int i = 0; i < std::min(path2.size(), path1.size()); ++i) {
        if (path1[i] != path2[i]) {
            return path1[i - 1];
        }
    }

    return path1.size() < path2.size() ? path1.back() : path2.back();
}