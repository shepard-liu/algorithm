// https://leetcode.cn/problems/average-of-levels-in-binary-tree/ Average of
// Levels in Binary Tree
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

inline void impl(TreeNode *root, vector<double> &sums, vector<int> &nums,
                 int level) {
    if (root == nullptr) {
        return;
    }

    if (level == sums.size()) {
        sums.push_back(0);
        nums.push_back(0);
    }

    sums[level] += root->val;
    nums[level]++;

    impl(root->left, sums, nums, level + 1);
    impl(root->right, sums, nums, level + 1);
}

inline vector<double> averageOfLevels(TreeNode *root) {
    std::vector<double> sums;
    std::vector<int> nums;
    impl(root, sums, nums, 0);
    for (int i = 0; i < sums.size(); ++i) {
        sums[i] /= nums[i];
    }
    return sums;
}