// https://leetcode.cn/problems/number-of-islands/ Number of Islands
#include <string>
#include <vector>
using namespace std;

inline void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,
                int i, int j) {
    visited[i][j] = true;

    int up = i - 1, left = j - 1, right = j + 1, down = i + 1;
    int m = grid.size(), n = grid[0].size();
    if (up >= 0 && grid[up][j] == '1' && !visited[up][j]) {
        dfs(grid, visited, up, j);
    }
    if (down < m && grid[down][j] == '1' && !visited[down][j]) {
        dfs(grid, visited, down, j);
    }
    if (left >= 0 && grid[i][left] == '1' && !visited[i][left]) {
        dfs(grid, visited, i, left);
    }
    if (right < n && grid[i][right] == '1' && !visited[i][right]) {
        dfs(grid, visited, i, right);
    }
}

inline int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int ans{0};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] || grid[i][j] == '0') {
                continue;
            }
            dfs(grid, visited, i, j);
            ans++;
        }
    }
    return ans;
}