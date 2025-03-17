// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Find the Index of the First Occurrence in a String
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline int strStr(string haystack, string needle) {
    std::vector<size_t> lps(needle.size(), 0);

    for (size_t i = 1; i < needle.size(); ++i) {
        size_t j = lps[i - 1];
        while (j > 0 && needle[j] != needle[i]) {
            j = lps[j - 1];
        }
        if (needle[j] == needle[i]) {
            lps[i] = j + 1;
        }
    }

    for (size_t i = 0, j = 0; i < haystack.size(); ++i) {
        while (j > 0 && needle[j] != haystack[i]) {
            j = lps[j - 1];
        }
        if (needle[j] == haystack[i]) {
            j++;
        }
        if (j == needle.size()) {
            return i - needle.size() + 1;
        }
    }
    return -1;
}