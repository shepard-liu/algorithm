// https://leetcode.cn/problems/valid-sudoku/ Valid Sudoku
#include <string>
#include <vector>
using namespace std;

inline bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        int filledCol = 0, filledRow = 0;
        for (int j = 0; j < 9; ++j) {
            int c1 = board[i][j];
            if (c1 != 46) {
                c1 -= 49;
                if ((filledRow & (1 << c1)) != 0) {
                    return false;
                } else {
                    filledRow |= (1 << c1);
                }
            }
            int c2 = board[j][i];
            if (c2 != 46) {
                c2 -= 49;
                if ((filledCol & (1 << c2)) != 0) {
                    return false;
                } else {
                    filledCol |= (1 << c2);
                }
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int filledBlock = 0;
            for (int m = 0; m < 3; ++m) {
                for (int n = 0; n < 3; ++n) {
                    int c = board[i * 3 + m][j * 3 + n];
                    if (c == 46) {
                        continue;
                    }
                    c -= 49;

                    if ((filledBlock & (1 << c)) != 0) {
                        return false;
                    } else {
                        filledBlock |= (1 << c);
                    }
                }
            }
        }
    }

    return true;
}