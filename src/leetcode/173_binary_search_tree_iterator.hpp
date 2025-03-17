// https://leetcode.cn/problems/binary-search-tree-iterator/ Binary Search Tree
// Iterator
#include <stack>
#include <string>
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

class BSTIterator {
    stack<TreeNode *> path;
    stack<std::pair<bool, bool>> visited;
    TreeNode *cur{};

   public:
    BSTIterator(TreeNode *root) {
        path.push(root);
        visited.push({false, false});
    }

    int next() {
        while (true) {
            auto [leftVisited, rightVisited] = visited.top();
            if (leftVisited && rightVisited) {
                path.pop();
                visited.pop();
                continue;
            }
            TreeNode *cur = path.top();
            if (!leftVisited) {
                visited.top().first = true;
                if (cur->left == nullptr) {
                } else {
                    path.push(cur->left);
                    visited.push({false, false});
                }
                continue;
                // left visited but right hasnt
            } else {
                int ret = cur->val;
                visited.top().second = true;
                if (cur->right == nullptr) {
                    path.pop();
                    visited.pop();
                } else {
                    path.push(cur->right);
                    visited.push({false, false});
                }
                return ret;
            }
        }
    }

    bool hasNext() {
        while (!path.empty() && visited.top().first == true &&
               visited.top().second == true) {
            path.pop();
            visited.pop();
        }
        return !path.empty();
    }
};