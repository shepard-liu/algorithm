// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/ Best Time
// to Buy and Sell Stock III
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) {
        return 0;
    }
    std::vector<int> peaks;
    std::vector<int> valleys;
    {
        int i = 0;
        while (i < prices.size() - 1 && prices[i] == prices[i + 1]) {
            i++;
        }
        if (i < prices.size() - 1 && prices[i] < prices[i + 1]) {
            valleys.push_back(prices[i]);
        }

        bool increasing = prices[i] < prices[i + 1];

        for (; i < prices.size() - 1; ++i) {
            if (increasing) {
                if (prices[i] > prices[i + 1]) {
                    increasing = false;
                    peaks.push_back(prices[i]);
                }
            } else {
                if (prices[i] < prices[i + 1]) {
                    increasing = true;
                    valleys.push_back(prices[i]);
                }
            }
        }

        while (i >= 1 && prices[i] == prices[i - 1]) {
            i--;
        }

        if (i >= 1 && prices[i] > prices[i - 1]) {
            peaks.push_back(prices[i]);
        }
    }
    int n = peaks.size();
    if (n == 0) {
        return 0;
    }

    vector<int> maxProfitsUntilI(n, 0);
    int minValley = valleys[0];
    int maxPro = 0;
    for (int i = 0; i < n; ++i) {
        minValley = min(valleys[i], minValley);
        maxPro = max(maxPro, peaks[i] - minValley);
        maxProfitsUntilI[i] = maxPro;
    }

    vector<int> maxProfitsFromI(n, 0);
    int maxPeak = peaks[n - 1];
    maxPro = 0;
    for (int i = n - 1; i >= 0; --i) {
        maxPeak = max(peaks[i], maxPeak);
        maxPro = max(maxPro, maxPeak - valleys[i]);
        maxProfitsFromI[i] = maxPro;
    }

    int ans{0};

    for (int i = 0; i < n; ++i) {
        ans = max(ans, maxProfitsUntilI[i] +
                           (i != n - 1 ? maxProfitsFromI[i + 1] : 0));
    }

    return ans;
}