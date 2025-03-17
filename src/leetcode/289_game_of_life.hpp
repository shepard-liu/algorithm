// https://leetcode.cn/problems/game-of-life/ Game of Life
#include <string>
#include <vector>
using namespace std;

inline void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> ans(board);
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int aliveCount = 0;
            for (int p = i - 1; p <= i + 1; ++p) {
                if (p < 0 || p >= m) {
                    continue;
                }
                for (int q = j - 1; q <= j + 1; ++q) {
                    if (q < 0 || q >= n) {
                        continue;
                    }
                    if (board[p][q] == 1) {
                        aliveCount++;
                    }
                }
            }

            if (board[i][j] == 1) {
                aliveCount--;
                if (aliveCount < 2) {
                    ans[i][j] = 0;
                }
                if (aliveCount > 3) {
                    ans[i][j] = 0;
                }
            } else {
                if (aliveCount == 3) {
                    ans[i][j] = 1;
                }
            }
        }
    }

    board = ans;
}