// https://leetcode.cn/problems/reverse-bits/ Reverse Bits
#include <bitset>
#include <cstdint>
#include <string>
#include <vector>
using namespace std;

inline uint32_t reverseBits(uint32_t n) {
    std::bitset<32> ans;
    std::bitset<32> num(n);
    for (int i = 0; i < 32; ++i) {
        ans[i] = num[32 - i - 1];
    }
    return ans.to_ulong();
}