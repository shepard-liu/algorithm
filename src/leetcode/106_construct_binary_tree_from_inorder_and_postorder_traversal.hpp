// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Construct Binary Tree from Inorder and Postorder Traversal
#include <algorithm>
#include <limits>
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

typedef std::pair<int, int> Range;

inline bool withinRange(const Range &range, int val) {
    return val >= range.first && val < range.second;
}

inline void buildTreeImpl(TreeNode *root, const vector<int> &inorder,
                          const vector<int> &postorder,
                          const unordered_map<int, int> &inorderLookup,
                          const unordered_map<int, int> &postorderLookup,
                          const Range &inorderRange,
                          const Range &postorderRange) {
    int val = root->val;
    int inorderPos = inorderLookup.at(val);
    Range inorderLeftRange = {inorderRange.first, inorderPos};
    Range inorderRightRange = {inorderPos + 1, inorderRange.second};
    Range postorderLeftRange = inorderLeftRange.first == inorderLeftRange.second
                                   ? std::make_pair(0, 0)
                                   : std::make_pair((int)inorder.size(), 0);
    for (int i = inorderLeftRange.first; i < inorderLeftRange.second; ++i) {
        int postorderPos = postorderLookup.at(inorder[i]);
        postorderLeftRange.first =
            std::min(postorderLeftRange.first, postorderPos);
        postorderLeftRange.second =
            std::max(postorderLeftRange.second, postorderPos);
    }
    postorderLeftRange.second++;

    Range postorderRightRange = {postorderLeftRange.second,
                                 postorderRange.second - 1};

    if (inorderLeftRange.first != inorderLeftRange.second) {
        root->left = new TreeNode(postorder[postorderLeftRange.second - 1]);
        buildTreeImpl(root->left, inorder, postorder, inorderLookup,
                      postorderLookup, inorderLeftRange, postorderLeftRange);
    }
    if (inorderRightRange.first != inorderRightRange.second) {
        root->right = new TreeNode(postorder[postorderRightRange.second - 1]);
        buildTreeImpl(root->right, inorder, postorder, inorderLookup,
                      postorderLookup, inorderRightRange, postorderRightRange);
    }
}

inline TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    TreeNode *root = new TreeNode(postorder.back());
    unordered_map<int, int> inorderLookup{};
    unordered_map<int, int> postorderLookup{};

    int n = inorder.size();

    for (int i = 0; i < n; ++i) {
        inorderLookup[inorder[i]] = i;
        postorderLookup[postorder[i]] = i;
    }

    buildTreeImpl(root, inorder, postorder, inorderLookup, postorderLookup,
                  {0, n}, {0, n});

    return root;
}