// https://leetcode.cn/problems/majority-element/ Majority Element
#include <cstddef>
#include <limits>
#include <vector>
using namespace std;

inline int majorityElement(vector<int>& nums) {
    size_t c = 0;
    int d = numeric_limits<int>::min();
    for (auto n : nums) {
        if (c == 0) {
            d = n;
            c = 1;
        } else if (d != n) {
            c--;
        } else {
            c++;
        }
    }
    return d;
}