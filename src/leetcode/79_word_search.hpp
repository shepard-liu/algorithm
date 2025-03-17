// https://leetcode.cn/problems/word-search/ Word Search
#include <string>
#include <vector>
using namespace std;

void dfs(bool& found, vector<vector<char>>& board, int i, int j, int k,
         string& word) {
    int m = board.size();
    int n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return;
    }

    char& c = board[i][j];
    if (c == '#') {
        return;
    }
    if (c != word[k]) {
        return;
    }
    k++;

    if (k == word.size()) {
        found = true;
        return;
    }

    char tmp = c;
    c = '#';
    dfs(found, board, i + 1, j, k, word);
    dfs(found, board, i - 1, j, k, word);
    dfs(found, board, i, j + 1, k, word);
    dfs(found, board, i, j - 1, k, word);

    c = tmp;
}

bool exist(vector<vector<char>>& board, string word) {
    bool found{false};
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            dfs(found, board, i, j, 0, word);
            if (found) {
                return true;
            }
        }
    }
    return false;
}