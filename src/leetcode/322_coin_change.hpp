// https://leetcode.cn/problems/coin-change/ Coin Change
#include <algorithm>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int IntMax = numeric_limits<int>::max() - 1;

inline int impl(vector<int>& coins, int amount, vector<int>& dp) {
    if (amount == 0) {
        return 0;
    }

    if (dp[amount] != -1) {
        return dp[amount];
    }

    int minSteps = IntMax;
    for (int i = 0; i < coins.size(); ++i) {
        if (amount - coins[i] >= 0) {
            minSteps = min(minSteps, impl(coins, amount - coins[i], dp) + 1);
        }
    }

    dp[amount] = minSteps;
    return minSteps;
}

inline int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);

    auto it = std::remove_if(coins.begin(), coins.end(),
                             [&](int c) { return c > amount; });
    coins.erase(it, coins.end());

    std::sort(coins.begin(), coins.end(), [](int a, int b) { return a > b; });

    int ans = impl(coins, amount, dp);
    return ans == IntMax ? -1 : ans;
}