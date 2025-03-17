#include "236_lowest_common_ancestor_of_a_binary_tree.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <tuple>
#include <vector>

#include "../test_utils.hpp"
typedef std::tuple<TreeNode*, TreeNode*, TreeNode*, int> TestCase;

inline void constructTree(TreeNode* root, int index,
                          const std::vector<std::vector<int>>& levels,
                          int level) {
    if (level == levels.size() - 1) {
        return;
    }
    auto nextLevel = levels[level + 1];
    int left = index * 2, right = left + 1;
    if (nextLevel[left] != -1) {
        root->left = new TreeNode(nextLevel[left]);
        constructTree(root->left, left, levels, level + 1);
    }
    if (nextLevel[right] != -1) {
        root->right = new TreeNode(nextLevel[right]);
        constructTree(root->right, right, levels, level + 1);
    }
}

inline TreeNode* treeFromLevels(const std::vector<std::vector<int>>& levels) {
    TreeNode* root = new TreeNode(levels.front().front());
    constructTree(root, 0, levels, 0);
    return root;
}

void test_lowest_common_ancestor_of_a_binary_tree(TestCase& c) {
    auto [r, p, q, ans] = c;
    std::cout << "p -> " << p->val << "; q -> " << q->val << std::endl;
    auto myAns = lowestCommonAncestor(r, p, q)->val;
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, lowest_common_ancestor_of_a_binary_tree) {
    TreeNode* t1 = treeFromLevels(
        {{0}, {1, 2}, {3, 4, 5, 6}, {7, 8, 9, 10, 11, 12, 13, 14, 15}});

    std::vector<TestCase> cases{{t1, t1->left->right, t1->right->left, 0},
                                {t1, t1->left->right->left, t1->left, 1}};

    for (TestCase& c : cases) {
        test_lowest_common_ancestor_of_a_binary_tree(c);
    }
}
