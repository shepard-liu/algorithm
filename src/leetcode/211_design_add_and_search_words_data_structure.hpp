// https://leetcode.cn/problems/design-add-and-search-words-data-structure/
// Design Add and Search Words Data Structure
#include <algorithm>
#include <cstddef>
#include <memory>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

inline int charIndex(char c) { return c - 'a'; }

inline char indexChar(int i) { return i + 'a'; }

class Trie {
   private:
    class Node {
        std::vector<std::shared_ptr<Node>> children;
        std::vector<char> childChars;
        bool isWord = false;

       public:
        Node() { children = std::vector<std::shared_ptr<Node>>(26, nullptr); }

        std::shared_ptr<Node> child(char c) {
            int idx = charIndex(c);
            if (children[idx] == nullptr) {
                children[idx] = std::make_shared<Node>();
                childChars.push_back(c);
            }
            return children[idx];
        }

        bool hasChild(char c) {
            int idx = charIndex(c);
            return children[idx] != nullptr;
        }

        const std::vector<char> chars() const { return childChars; }

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

    std::shared_ptr<Node> startsWith(string prefix) {
        auto cur = root;
        for (char c : prefix) {
            if (!cur->hasChild(c)) {
                return nullptr;
            }
            cur = cur->child(c);
        }
        return cur;
    }

    bool match(string pattern) {
        stack<std::pair<std::shared_ptr<Node>, int>,
              std::vector<std::pair<std::shared_ptr<Node>, int>>>
            stk;
        stk.push({root, 0});
        while (!stk.empty()) {
            auto [cur, idx] = stk.top();
            stk.pop();
            if (idx == pattern.size()) {
                if (cur->word()) {
                    return true;
                } else {
                    continue;
                }
            }
            char c = pattern[idx];

            if (c == '.') {
                for (auto childChar : cur->chars()) {
                    stk.push({cur->child(childChar), idx + 1});
                }
            } else if (cur->hasChild(c)) {
                stk.push({cur->child(c), idx + 1});
            }
        }

        return false;
    }
};

class WordDictionary {
    Trie prefixTrie;
    Trie suffixTrie;

   public:
    WordDictionary() {}

    void addWord(string word) {
        prefixTrie.insert(word);
        std::reverse(word.begin(), word.end());
        suffixTrie.insert(word);
    }

    bool search(string word) {
        return prefixTrie.match(word);
        // int prefixLen = 0, suffixLen = 0;
        // while (prefixLen < word.size() && word[prefixLen] != '.') {
        //     prefixLen++;
        // }

        // if (prefixLen == word.size()) {
        //     return prefixTrie.search(word);
        // }

        // string reversedWord = word;
        // std::reverse(reversedWord.begin(), reversedWord.end());
        // while (suffixLen < reversedWord.size() &&
        //        reversedWord[suffixLen] != '.') {
        //     suffixLen++;
        // }

        // if (prefixLen >= suffixLen) {
        //     return prefixTrie.match(word);
        // } else {
        //     return suffixTrie.match(reversedWord);
        // }
    }
};