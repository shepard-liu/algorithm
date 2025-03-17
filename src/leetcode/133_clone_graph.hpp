// https://leetcode.cn/problems/clone-graph/ Clone Graph
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
   public:
    int val;
    vector<Trie*> neighbors;

    Trie() {
        val = 0;
        neighbors = vector<Trie*>();
    }

    Trie(int _val) {
        val = _val;
        neighbors = vector<Trie*>();
    }

    Trie(int _val, vector<Trie*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

inline void dfs(Trie* node, unordered_map<Trie*, Trie*>& mapping) {
    if (mapping.find(node) != mapping.end()) {
        return;
    }

    Trie* clone = new Trie(node->val, node->neighbors);
    mapping[node] = clone;

    for (auto& n : node->neighbors) {
        dfs(n, mapping);
    }
}

inline Trie* cloneGraph(Trie* node) {
    if (node == nullptr) {
        return nullptr;
    }
    unordered_map<Trie*, Trie*> mapping;
    dfs(node, mapping);

    for (auto& [_, newNode] : mapping) {
        for (auto& nb : newNode->neighbors) {
            nb = mapping[nb];
        }
    }
    return mapping[node];
}