// https://leetcode.cn/problems/triangle/ Triangle
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int dfs(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i,
               int j) {
    int n = triangle.size();
    if (i >= n) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int minSum =
        min(dfs(triangle, dp, i + 1, j), dfs(triangle, dp, i + 1, j + 1)) +
        triangle[i][j];

    dp[i][j] = minSum;
    return minSum;
}

inline int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>{});
    for (int i = 0; i < triangle.size(); ++i) {
        dp[i].resize(triangle[i].size(), -1);
    }

    return dfs(triangle, dp, 0, 0);
}