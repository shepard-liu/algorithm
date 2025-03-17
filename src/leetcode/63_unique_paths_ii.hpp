// https://leetcode.cn/problems/unique-paths-ii/ Unique Paths II
#include <string>
#include <vector>
using namespace std;

inline int dfs(vector<vector<int>>& grid, int i, int j,
               vector<vector<int>>& dp) {
    int m = grid.size(), n = grid.front().size();

    if (i == m - 1 && j == n - 1) {
        return 1;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int paths{0};
    if (i != m - 1 && grid[i + 1][j] == 0) {
        paths += dfs(grid, i + 1, j, dp);
    }
    if (j != n - 1 && grid[i][j + 1] == 0) {
        paths += dfs(grid, i, j + 1, dp);
    }

    dp[i][j] = paths;
    return paths;
}

inline int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid.front().size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return obstacleGrid.front().front() == 1 ? 0 : dfs(obstacleGrid, 0, 0, dp);
}