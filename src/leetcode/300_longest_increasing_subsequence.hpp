// https://leetcode.cn/problems/longest-increasing-subsequence/ Longest
// Increasing Subsequence
#include <algorithm>
#include <limits>
#include <string>
#include <vector>
using namespace std;

inline int impl(vector<int>& nums, int end, vector<int>& dp) {
    if (dp[end] != -1) {
        return dp[end];
    }

    int maxLen = 1;
    for (int i = 0; i < end; ++i) {
        if (nums[i] < nums[end]) {
            maxLen = max(maxLen, impl(nums, i, dp) + 1);
        }
    }

    dp[end] = maxLen;
    return maxLen;
}

inline int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    int ans{0};
    for (int i = 0; i < nums.size(); ++i) {
        ans = max(ans, impl(nums, i, dp));
    }

    return ans;
}