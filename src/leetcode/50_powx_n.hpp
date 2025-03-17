// https://leetcode.cn/problems/powx-n/ Pow(x, n)
#include <cstdint>
#include <string>
#include <vector>
using namespace std;

inline double myPow(double x, int n) {
    if (x == 0) {
        return 0;
    }
    if (x == 1) {
        return 1;
    }

    uint64_t p = n;

    if (n < 0) {
        x = 1.0 / x;
        p = -int64_t(n);
    }

    double ans{1.0};
    double pw{x};

    while (p != 0) {
        ans *= (p & 1) == 1 ? pw : 1;
        pw *= pw;
        p >>= 1;
    }
    return ans;
}