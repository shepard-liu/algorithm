// https://leetcode.cn/problems/longest-common-subsequence/ Longest Common
// Subsequence
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline int dfs(string& s1, string& s2, int i, int j, vector<vector<int>>& dp,
               int& ans) {
    int m = s1.size(), n = s2.size();

    if (i == m || j == n) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int maxLen = 0;
    if (s1[i] == s2[j]) {
        maxLen = dfs(s1, s2, i + 1, j + 1, dp, ans) + 1;
    } else {
        int iNext = dfs(s1, s2, i + 1, j, dp, ans);
        int jNext = dfs(s1, s2, i, j + 1, dp, ans);
        maxLen = max(iNext, jNext);
    }

    if (maxLen > ans) {
        ans = maxLen;
    }

    dp[i][j] = maxLen;
    return maxLen;
}

inline int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    int ans{0};
    dfs(text1, text2, 0, 0, dp, ans);
    return ans;
}