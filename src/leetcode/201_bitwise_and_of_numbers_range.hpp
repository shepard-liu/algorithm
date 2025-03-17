// https://leetcode.cn/problems/bitwise-and-of-numbers-range/ Bitwise AND of
// Numbers Range
#include <bitset>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline int rangeBitwiseAnd(int left, int right) {
    uint32_t bits = uint32_t(1) << 31;
    uint32_t l = ~right;
    uint32_t r = ~left;
    uint32_t ans = 0;
    while (bits != 0) {
        uint32_t n = bits + l;
        if ((l <= n && n <= r) || (bits & l) > 0 || (bits & r) > 0) {
            ans |= bits;
        }
        bits = bits >> 1;
    }
    return ~ans;
}