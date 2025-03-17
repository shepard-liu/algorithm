// https://leetcode.cn/problems/jump-game/ Jump Game
#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;

inline bool canJump(vector<int>& nums) {
    size_t farthestIdx = 0;
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        farthestIdx = std::max(farthestIdx, nums[i] + i);
        if (nums[i] == 0 && farthestIdx <= i) {
            return false;
        }
    }
    return true;
}
