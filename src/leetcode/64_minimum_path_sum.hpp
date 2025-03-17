// https://leetcode.cn/problems/minimum-path-sum/ Minimum Path Sum
#include <algorithm>
#include <limits>
#include <string>
#include <vector>
using namespace std;

inline int dfs(vector<vector<int>>& grid, int i, int j,
               vector<vector<int>>& dp) {
    int m = grid.size();
    int n = grid[0].size();

    if (i == m - 1 && j == n - 1) {
        return grid[i][j];
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int minSum{numeric_limits<int>::max()};
    if (i != m - 1) {
        minSum = dfs(grid, i + 1, j, dp);
    }
    if (j != n - 1) {
        minSum = min(minSum, dfs(grid, i, j + 1, dp));
    }
    minSum += grid[i][j];

    dp[i][j] = minSum;
    return minSum;
}

inline int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return dfs(grid, 0, 0, dp);
}
