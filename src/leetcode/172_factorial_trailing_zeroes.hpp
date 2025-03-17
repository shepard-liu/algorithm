// https://leetcode.cn/problems/factorial-trailing-zeroes/ Factorial Trailing
// Zeroes
#include <string>
#include <vector>
using namespace std;

inline int trailingZeroes(int n) {
    uint64_t last = 1;
    int count = 0;
    for (uint64_t i = 2; i <= n; ++i) {
        last *= i;
        while (last % 10 == 0) {
            last /= 10;
            count++;
        }
        last = last % 10000000;
    }
    return count;
}