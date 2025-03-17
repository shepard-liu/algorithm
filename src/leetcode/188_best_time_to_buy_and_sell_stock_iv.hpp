// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/ Best Time to
// Buy and Sell Stock IV
#include <algorithm>
#include <limits>
#include <string>
#include <utility>
#include <vector>
using namespace std;

inline int IntMin = numeric_limits<int>::min();

inline int dfs(vector<int>& prices, int i, int j, bool hold,
               vector<vector<pair<int, int>>>& dp) {
    if (i == 0) {
        return hold ? -prices[0] : 0;
    }

    if (hold && dp[i][j].second != IntMin) {
        return dp[i][j].second;
    } else if (!hold && dp[i][j].first != IntMin) {
        return dp[i][j].first;
    }

    int maxPro{};
    if (hold) {
        maxPro = max(dfs(prices, i - 1, j, false, dp) - prices[i],
                     dfs(prices, i - 1, j, true, dp));
        dp[i][j].second = maxPro;

    } else if (j != 0) {
        maxPro = max(dfs(prices, i - 1, j - 1, true, dp) + prices[i],
                     dfs(prices, i - 1, j, false, dp));
        dp[i][j].first = maxPro;
    } else {
        maxPro = dfs(prices, i - 1, 0, false, dp);
        dp[i][j].first = maxPro;
    }

    return maxPro;
}

inline int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<pair<int, int>>> dp(
        n, vector<pair<int, int>>(k + 1, {IntMin, IntMin}));
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = max(ans, dfs(prices, n - 1, i, false, dp));
    }
    return ans;
}