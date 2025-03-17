// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/ Best Time to
// Buy and Sell Stock

#include <cstddef>
#include <limits>
#include <vector>
using namespace std;

inline int maxProfit(vector<int>& prices) {
    int min = std::numeric_limits<int>::max();
    int maxPro = 0;
    for (auto p : prices) {
        if (min > p) {
            min = p;
        }
        if (p - min > maxPro) {
            maxPro = p - min;
        }
    }
    return maxPro;
}