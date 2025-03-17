// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// Longest Substring Without Repeating Characters
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

inline int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0;
    unordered_set<char> chars;
    int maxLen = 0;

    while (j < s.size()) {
        char c = s[j];
        unordered_set<char>::iterator dupIt = chars.find(c);
        while (dupIt != chars.end()) {
            chars.erase(s[i]);
            i++;
            dupIt = chars.find(c);
        }

        chars.insert(c);
        j++;
        if (chars.size() > maxLen) {
            maxLen = chars.size();
        }
    }
    return maxLen;
}