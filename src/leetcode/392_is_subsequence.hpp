// https://leetcode.cn/problems/is-subsequence/ Is Subsequence
#include <string>
#include <vector>
using namespace std;

inline bool isSubsequence(string s, string t) {
    size_t j = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        bool found = false;
        while (j < t.size()) {
            if (t[j++] == c) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}