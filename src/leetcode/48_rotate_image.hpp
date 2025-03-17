// https://leetcode.cn/problems/rotate-image/ Rotate Image
#include <string>
#include <type_traits>
#include <vector>
using namespace std;

inline void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int cur = 0;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < (n + 1) / 2; ++j) {
            int ii = i, jj = j;
            cur = matrix[ii][jj];
            for (int k = 0; k < 5; ++k) {
                std::swap(matrix[ii][jj], cur);
                int tmp = ii;
                ii = jj;
                jj = n - 1 - tmp;
            }
        }
    }
}