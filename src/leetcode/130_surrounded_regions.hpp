// https://leetcode.cn/problems/surrounded-regions/ Surrounded Regions
#include <string>
#include <vector>
using namespace std;

inline void dfs(vector<vector<char>>& board, int i, int j, char setVal) {
    int m = board.size();
    int n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return;
    }
    if (board[i][j] != 'O') {
        return;
    }
    board[i][j] = 'P';
    dfs(board, i - 1, j, setVal);
    dfs(board, i + 1, j, setVal);
    dfs(board, i, j - 1, setVal);
    dfs(board, i, j + 1, setVal);
}

inline void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
        dfs(board, i, 0, 'P');
        dfs(board, i, n - 1, 'P');
    }
    for (int i = 0; i < n; ++i) {
        dfs(board, 0, i, 'P');
        dfs(board, m - 1, i, 'P');
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char& c = board[i][j];
            if (c == 'O') {
                c = 'X';
            } else if (c == 'P') {
                c = 'O';
            }
        }
    }
}