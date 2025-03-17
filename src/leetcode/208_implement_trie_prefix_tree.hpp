// https://leetcode.cn/problems/implement-trie-prefix-tree/ Implement Trie
// (Prefix Tree)
#include <cstddef>
#include <memory>
#include <string>
#include <vector>
using namespace std;

inline int charIndex(char c) { return c - 'a'; }

inline char indexChar(int i) { return i + 'a'; }

class Trie {
   private:
    class Node {
        std::vector<std::shared_ptr<Node>> children;
        bool isWord = false;

       public:
        Node() { children = std::vector<std::shared_ptr<Node>>(26, nullptr); }

        std::shared_ptr<Node> child(char c) {
            int idx = charIndex(c);
            if (children[idx] == nullptr) {
                children[idx] = std::make_shared<Node>();
            }
            return children[idx];
        }

        bool hasChild(char c) {
            int idx = charIndex(c);
            return children[idx] != nullptr;
        }

        void setWord() { isWord = true; }

        bool word() { return isWord; }
    };

    std::shared_ptr<Node> root{nullptr};

   public:
    Trie() { root = make_shared<Node>(); }

    void insert(string word) {
        auto cur = root;
        for (char c : word) {
            cur = cur->child(c);
        }
        cur->setWord();
    }

    bool search(string word) {
        auto cur = root;
        for (char c : word) {
            if (!cur->hasChild(c)) {
                return false;
            }
            cur = cur->child(c);
        }
        return cur->word();
    }

    bool startsWith(string prefix) {
        auto cur = root;
        for (char c : prefix) {
            if (!cur->hasChild(c)) {
                return false;
            }
            cur = cur->child(c);
        }
        return true;
    }
};
