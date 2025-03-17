// https://leetcode.cn/problems/reverse-words-in-a-string/ Reverse Words in a
// String
#include <algorithm>
#include <cstddef>
#include <functional>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

inline string reverseWords(string s) {
    if (s.size() == 0) {
        return "";
    }
    std::vector<string> words;

    int wordStart = -1;

    for (size_t i = 0; i < s.size(); ++i) {
        if (wordStart != -1) {
            if (s[i] == ' ') {
                words.push_back(s.substr(wordStart, i - wordStart));
                wordStart = -1;
            }
        } else {
            if (s[i] != ' ') {
                wordStart = i;
            }
        }
    }

    if (s.back() != ' ') {
        words.push_back(s.substr(wordStart));
    }

    return std::accumulate(
               words.rbegin(), words.rend(), string(""),
               [](const string& a, const string& b) { return a + ' ' + b; })
        .substr(1);
}