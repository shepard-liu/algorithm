// https://leetcode.cn/problems/interleaving-string/ Interleaving String
#include <string>
#include <vector>
using namespace std;

inline bool dfs(string& s1, string& s2, string& s3, int i, int j,
                vector<vector<int>>& dp) {
    int m = s1.size(), n = s2.size(), t = s3.size();
    int k = i + j;
    if (k == t) {
        return true;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    bool canS1Next =
        i != m && s1[i] == s3[k] ? dfs(s1, s2, s3, i + 1, j, dp) : false;
    bool canS2Next =
        j != n && s2[j] == s3[k] ? dfs(s1, s2, s3, i, j + 1, dp) : false;
    bool canNext = canS1Next || canS2Next;
    dp[i][j] = canNext;
    return canNext;
}

inline bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size(), t = s3.size();
    if (m + n != t) {
        return false;
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    return dfs(s1, s2, s3, 0, 0, dp);
}