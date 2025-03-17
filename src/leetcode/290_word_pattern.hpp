// https://leetcode.cn/problems/word-pattern/ Word Pattern
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

inline bool wordPattern(string pattern, string s) {
    unordered_map<char, string> mapping{};
    unordered_map<string, char> inverse{};

    int p = 0;
    for (auto c : pattern) {
        if (p == s.size()) {
            return false;
        }
        int q = p;
        while (q < s.size() && s[q] != ' ') {
            q++;
        }
        string word = s.substr(p, q - p);
        p = q;
        while (s[p] == ' ') {
            p++;
        }
        auto it = mapping.find(c);
        if (it != mapping.end()) {
            if (word != it->second) {
                return false;
            }
            if (inverse[word] != c) {
                return false;
            }
        } else if (inverse.find(word) != inverse.end()) {
            return false;
        } else {
            mapping.emplace(c, word);
            inverse.emplace(word, c);
        }
    }

    if (p != s.size()) {
        return false;
    }
    return true;
}