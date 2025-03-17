// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/ Best Time to
// Buy and Sell Stock II
#include <cstddef>
#include <vector>
using namespace std;

inline int maxProfit(vector<int>& prices) {
    if (prices.size() == 0 || prices.size() == 1) {
        return 0;
    }
    int maxPro = 0;
    int min = prices[0];
    bool increasing = prices[1] >= prices[0];
    for (size_t i = 1; i < prices.size(); ++i) {
        if (increasing == false) {
            if (prices[i] >= prices[i - 1]) {
                min = prices[i - 1];
                increasing = true;
            }
        } else if (increasing == true) {
            if (prices[i] < prices[i - 1]) {
                increasing = false;
                maxPro += prices[i - 1] - min;
            }
        }
    }
    if (increasing) {
        maxPro += prices.back() - min;
    }

    return maxPro;
}