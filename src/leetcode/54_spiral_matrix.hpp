// https://leetcode.cn/problems/spiral-matrix/ Spiral Matrix
#include <limits>
#include <string>
#include <vector>
using namespace std;

inline vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    int nElems = nRows * nCols;
    ans.reserve(nElems);
    int nan = std::numeric_limits<int>::max();

    int i = 0, j = 0;
    while (ans.size() < nElems) {
        while (j < nCols && matrix[i][j] != nan) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = nan;
            ++j;
        }
        j--;
        i++;
        while (i < nRows && matrix[i][j] != nan) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = nan;
            ++i;
        }
        i--;
        j--;
        while (j >= 0 && matrix[i][j] != nan) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = nan;
            --j;
        }
        j++;
        i--;
        while (i >= 0 && matrix[i][j] != nan) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = nan;
            --i;
        }
        i++;
        j++;
    }
    return ans;
}