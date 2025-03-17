// https://leetcode.cn/problems/longest-palindromic-substring/ Longest
// Palindromic Substring
#include <string>
#include <vector>
using namespace std;

inline vector<int>& dfs(string& s, int start, vector<vector<int>>& dp,
                        int& ans_start, int& ans_len) {
    int n = s.size();
    if (start == n - 1) {
        dp[start].push_back(1);
        return dp[start];
    }

    if (dp[start].size() != 0) {
        return dp[start];
    }

    vector<int>& ret = dp[start];
    ret.push_back(1);

    if (s[start + 1] == s[start]) {
        ret.push_back(2);
        if (ans_len < 2) {
            ans_len = 2;
            ans_start = start;
        }
    }

    vector<int>& lens = dfs(s, start + 1, dp, ans_start, ans_len);
    for (int len : lens) {
        if (len + start + 1 >= n) {
            continue;
        }
        if (s[start] == s[len + start + 1]) {
            int newLen = len + 2;
            if (newLen > ans_len) {
                ans_start = start;
                ans_len = newLen;
            }
            ret.push_back(newLen);
        }
    }

    return ret;
}

inline string longestPalindrome(string s) {
    int ans_start{0}, ans_len{1};
    vector<vector<int>> dp(s.size(), vector<int>());

    dfs(s, 0, dp, ans_start, ans_len);
    return s.substr(ans_start, ans_len);
}