// https://leetcode.cn/problems/ipo/ IPO
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

inline int findMaximizedCapital(int k, int w, vector<int>& profits,
                                vector<int>& capital) {
    vector<pair<int, int>> proCaps{};
    int n = profits.size();
    proCaps.reserve(n);

    for (int i = 0; i < n; ++i) {
        proCaps.push_back({profits[i], capital[i]});
    }
    std::sort(proCaps.begin(), proCaps.end(),
              [](const pair<int, int>& a, const pair<int, int>& b) {
                  return a.second < b.second;
              });

    priority_queue<int> heap;
    int end = 0;
    for (int i = 0; i < k; ++i) {
        while (end < n && proCaps[end].second <= w) {
            heap.push(proCaps[end].first);
            end++;
        }
        if (heap.empty()) {
            break;
        }
        w += heap.top();
        heap.pop();
    }

    return w;
}