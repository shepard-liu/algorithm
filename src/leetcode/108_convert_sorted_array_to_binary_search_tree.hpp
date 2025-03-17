// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
// Convert Sorted Array to Binary Search Tree
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

void distributeNums(TreeNode *&root, vector<int> &nums, int from, int to) {
    if (from >= to) {
        return;
    }

    int mid = (to + from) / 2;
    root = new TreeNode(nums[mid]);
    distributeNums(root->left, nums, from, mid);
    distributeNums(root->right, nums, mid + 1, to);
}

inline TreeNode *sortedArrayToBST(vector<int> &nums) {
    TreeNode *root = nullptr;

    distributeNums(root, nums, 0, nums.size());

    return root;
}