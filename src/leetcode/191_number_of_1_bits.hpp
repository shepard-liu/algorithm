// https://leetcode.cn/problems/number-of-1-bits/ Number of 1 Bits
#include <string>
#include <vector>
using namespace std;

inline int hammingWeight(int n) {
    int ans{0};
    while (n != 0) {
        ans += n & 1;
        n >>= 1;
    }
    return ans;
}