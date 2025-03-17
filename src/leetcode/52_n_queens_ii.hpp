// https://leetcode.cn/problems/n-queens-ii/ N-Queens II
#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline void dfs(int& ans, int n, int i, int diag1, int diag2, int rows) {
    if (i == n) {
        ans++;
        return;
    }
    for (int k = 0; k < n; ++k) {
        if ((rows & (1 << k)) != 0 || (diag1 & (1 << (i + k))) != 0 ||
            (diag2 & (1 << (k - i + n - 1))) != 0) {
            continue;
        }
        diag1 |= 1 << (i + k);
        diag2 |= 1 << (k - i + n - 1);
        rows |= 1 << k;

        dfs(ans, n, i + 1, diag1, diag2, rows);

        diag1 ^= 1 << (i + k);
        diag2 ^= 1 << (k - i + n - 1);
        rows ^= 1 << k;
    }
}

inline int totalNQueens(int n) {
    int ans{0};
    dfs(ans, n, 0, 0, 0, 0);
    return ans;
}