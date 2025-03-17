// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
// Populating Next Right Pointers in Each Node II
#include <string>
#include <vector>
using namespace std;

class Trie {
   public:
    int val;
    Trie* left;
    Trie* right;
    Trie* next;

    Trie() : val(0), left(NULL), right(NULL), next(NULL) {}

    Trie(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Trie(int _val, Trie* _left, Trie* _right, Trie* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

inline void preorderTraverse(Trie* root, std::vector<vector<Trie*>>& levels,
                             int level) {
    if (level == levels.size()) {
        levels.push_back({});
    }

    if (root == nullptr) {
        return;
    }

    levels[level].push_back(root);
    preorderTraverse(root->left, levels, level + 1);
    preorderTraverse(root->right, levels, level + 1);
}

inline Trie* connect(Trie* root) {
    std::vector<std::vector<Trie*>> levels{};
    preorderTraverse(root, levels, 0);

    for (auto& lnodes : levels) {
        for (int i = 0; i < (int)lnodes.size() - 1; ++i) {
            lnodes[i]->next = lnodes[i + 1];
        }
    }

    return root;
}