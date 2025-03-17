// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/ Binary
// Tree Zigzag Level Order Traversal
#include <algorithm>
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

inline void impl(TreeNode *root, std::vector<std::vector<int>> &ans,
                 int level) {
    if (root == nullptr) {
        return;
    }

    if (level == ans.size()) {
        ans.push_back({});
    }

    ans[level].push_back(root->val);
    impl(root->left, ans, level + 1);
    impl(root->right, ans, level + 1);
}

inline vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int>> levels{};
    impl(root, levels, 0);
    for (int i = 0; i < levels.size(); i++) {
        if (i % 2 == 1) {
            std::reverse(levels[i].begin(), levels[i].end());
        }
    }
    return levels;
}
