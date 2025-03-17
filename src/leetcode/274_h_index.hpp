// https://leetcode.cn/problems/h-index/ H-Index
#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;

inline int hIndex(vector<int>& citations) {
    std::sort(citations.begin(), citations.end(),
              [](int a, int b) { return a > b; });
    for (size_t i = 0; i < citations.size(); ++i) {
        if (citations[i] < int(i + 1)) {
            return i;
        }
    }
    return citations.size();
}
