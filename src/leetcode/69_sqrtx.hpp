// https://leetcode.cn/problems/sqrtx/ Sqrt(x)
#include <string>
#include <vector>
using namespace std;

int mySqrt(int x) {
    if (x == 0) {
        return 0;
    }
    if (x == 1) {
        return 1;
    }
    uint64_t l = 0, r = x;
    while (l + 1 < r) {
        uint64_t mid = (l + r) / 2;
        if (mid * mid > x) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
}