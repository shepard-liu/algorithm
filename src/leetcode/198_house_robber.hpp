// https://leetcode.cn/problems/house-robber/ House Robber
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int robImpl(vector<int>& nums, vector<int>& dp, int start) {
    int n = nums.size();
    if (start >= n) {
        return 0;
    }
    if (dp[start] != -1) {
        return dp[start];
    }
    if (start == n - 1) {
        return nums[n - 1];
    }

    int res = std::max(robImpl(nums, dp, start + 2) + nums[start],
                       robImpl(nums, dp, start + 3) + nums[start + 1]);
    dp[start] = res;
    return res;
}

inline int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return robImpl(nums, dp, 0);
}