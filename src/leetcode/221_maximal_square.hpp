// https://leetcode.cn/problems/maximal-square/ Maximal Square
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int dfs(vector<vector<char>>& matrix, int i, int j,
               vector<vector<int>>& dp, int& ans) {
    int m = matrix.size(), n = matrix[0].size();
    if (i == m || j == n) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int rMax = dfs(matrix, i + 1, j, dp, ans);
    int bMax = dfs(matrix, i, j + 1, dp, ans);
    if (matrix[i][j] == '0') {
        dp[i][j] = 0;
        return 0;
    }
    int maxSideLen = 1;
    int rbMax = dfs(matrix, i + 1, j + 1, dp, ans);
    maxSideLen += min({rbMax, rMax, bMax});

    if (maxSideLen > ans) {
        ans = maxSideLen;
    }
    dp[i][j] = maxSideLen;
    return maxSideLen;
}

inline int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans{0};
    dfs(matrix, 0, 0, dp, ans);
    return ans * ans;
}