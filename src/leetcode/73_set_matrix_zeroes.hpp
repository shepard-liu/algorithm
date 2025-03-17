// https://leetcode.cn/problems/set-matrix-zeroes/ Set Matrix Zeroes
#include <string>
#include <vector>
using namespace std;

inline void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    std::vector<bool> zeroRows(m, false);
    std::vector<bool> zeroCols(n, false);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (zeroRows[i] || zeroCols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}