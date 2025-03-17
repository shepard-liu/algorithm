// https://leetcode.cn/problems/edit-distance/ Edit Distance
#include <algorithm>
#include <deque>
#include <limits>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

inline int dfs(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
    int m = s1.size(), n = s2.size();
    if (i == m || j == n) {
        return max(m - i, n - j);
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int minDist{numeric_limits<int>::max()};
    if (s1[i] == s2[j]) {
        minDist =
            min({dfs(s1, s2, i + 1, j + 1, dp), dfs(s1, s2, i, j + 1, dp) + 1,
                 dfs(s1, s2, i + 1, j, dp) + 1});
    } else {
        minDist =
            min({dfs(s1, s2, i + 1, j + 1, dp) + 1,
                 dfs(s1, s2, i, j + 1, dp) + 1, dfs(s1, s2, i + 1, j, dp) + 1});
    }
    dp[i][j] = minDist;

    return minDist;
}

inline int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return dfs(word1, word2, 0, 0, dp);
}