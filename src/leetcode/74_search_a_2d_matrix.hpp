// https://leetcode.cn/problems/search-a-2d-matrix/ Search a 2D Matrix
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0;
    int right = n * m;

    while (left != right) {
        int mid = (left + right) / 2;
        int i = mid / n;
        int j = mid % n;
        int num = matrix[i][j];
        if (left + 1 == right) {
            return num == target;
        }
        if (target > num) {
            left = mid;
        } else if (target < num) {
            right = mid;
        } else {
            return true;
        }
    }

    return false;
}