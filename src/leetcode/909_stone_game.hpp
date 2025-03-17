// https://leetcode.cn/problems/stone-game/ Stone Game
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int IntMax = std::numeric_limits<int>::max() - 1;

inline std::pair<int, int> getIndex(int seq, int n) {
    int ilb = (seq - 1) / n;
    int jlb = ilb % 2 == 0 ? (seq - 1) % n : (n - 1 - (seq - 1) % n);
    return {n - 1 - ilb, jlb};
}

inline bool isEnd(int seq, int n) { return seq == n * n; }

inline void dfs(vector<vector<int>>& board, int seq, vector<vector<int>>& dp,
                int step) {
    int n = board.size();
    auto [i, j] = getIndex(seq, n);
    int& minSteps = dp[i][j];

    if (step >= minSteps) {
        return;
    } else {
        minSteps = step;
    }

    for (int k = 1; k <= 6; ++k) {
        int nextSeq = seq + k;
        if (nextSeq > n * n) {
            break;
        }
        auto [nextI, nextJ] = getIndex(nextSeq, n);
        int next = board[nextI][nextJ];
        if (next >= 1) {
            dfs(board, next, dp, step + 1);
        } else {
            dfs(board, nextSeq, dp, step + 1);
        }
    }
}

inline int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<vector<int>> dp(n, vector<int>(n, IntMax));
    dfs(board, 1, dp, 0);
    auto [endI, endJ] = getIndex(n * n, n);
    if (dp[endI][endJ] == IntMax) {
        return -1;
    }
    // for (int i = 1; i <= n * n; ++i) {
    //     auto [p, q] = getIndex(i, n);
    //     std::cout << "(" << i << ")" << board[p][q] << "["
    //               << (dp[p][q] == IntMax ? -9 : dp[p][q]) << "]"
    //               << "\t";
    //     if (i % n == 0) {
    //         std::cout << "\n";
    //     }
    // }
    return dp[endI][endJ];
}