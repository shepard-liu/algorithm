// https://leetcode.cn/problems/jump-game-ii/ Jump Game II
#include <algorithm>
#include <cstddef>
#include <limits>
#include <vector>
using namespace std;

// 若出现可能不可达的情况：
inline int jump(vector<int>& nums) {
    size_t farthestIdx = 0;
    size_t minSteps = 0;
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        farthestIdx = std::max(farthestIdx, nums[i] + i);
        if (farthestIdx >= nums.size() - 1) {
            minSteps++;
        }
    }
    return true;
}