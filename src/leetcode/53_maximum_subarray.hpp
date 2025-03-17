// https://leetcode.cn/problems/maximum-subarray/ Maximum Subarray
#include <algorithm>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>
using namespace std;

inline int maxSubArray(vector<int>& nums) {
    int maxSum = std::numeric_limits<int>::min();

    int lastSum = maxSum;
    for (int i = 0; i < nums.size(); ++i) {
        if (lastSum >= 0) {
            lastSum += nums[i];
        } else {
            lastSum = nums[i];
        }
        if (lastSum > maxSum) {
            maxSum = lastSum;
        }
    }
    return maxSum;
}

inline int maxSubArray_PrefixMinMax(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int leftMinSum = 0;
    int ans = nums[0];

    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        ans = max(ans, sum - leftMinSum);
        leftMinSum = min(sum, leftMinSum);
    }

    return ans;
}