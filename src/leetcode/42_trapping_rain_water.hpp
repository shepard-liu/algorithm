// https://leetcode.cn/problems/trapping-rain-water/ Trapping Rain Water
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stack>
#include <type_traits>
#include <vector>
using namespace std;

inline int trapRange(vector<int>& height, int from, int to) {
    // trim left right
    while (from < to && height[from + 1] > height[from]) {
        from++;
    }
    while (from < to && height[to - 1] > height[to]) {
        to--;
    }
    // std::cout << from << " - " << to << std::endl;
    if (from + 1 >= to) {
        return 0;
    }
    // std::cout << "computing from:" << from << " to:" << to << std::endl;
    int h1Idx = from, h2Idx = from;
    int h1 = 0, h2 = 0;
    for (int i = from; i <= to; ++i) {
        if (height[i] > h1) {
            h2 = h1;
            h2Idx = h1Idx;
            h1 = height[i];
            h1Idx = i;
        }
        if (height[i] >= h2 && i != h1Idx) {
            h2 = height[i];
            h2Idx = i;
        }
    }
    if (h1Idx == h2Idx) {
        return 0;
    }
    if (h1Idx > h2Idx) {
        std::swap(h1Idx, h2Idx);
        std::swap(h1, h2);
    }

    // std::cout << "h1:" << h1 << "; h1Idx:" << h1Idx << "; h2:" << h2
    //           << "; h2Idx:" << h2Idx << std::endl;
    int sum = std::min(h1, h2) * (h2Idx - h1Idx - 1);
    for (int i = h1Idx + 1; i <= h2Idx - 1; ++i) {
        sum -= height[i];
    }
    // std::cout << "sum=" << sum << std::endl;
    return sum + trapRange(height, from, h1Idx) + trapRange(height, h2Idx, to);
}

inline int trap(vector<int>& height) {
    return trapRange(height, 0, height.size() - 1);
}
