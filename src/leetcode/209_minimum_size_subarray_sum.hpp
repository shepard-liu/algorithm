// https://leetcode.cn/problems/minimum-size-subarray-sum/ Minimum Size Subarray
// Sum
#include <limits>
#include <vector>
using namespace std;

inline int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, r = 0;
    int sum = 0;
    int minLen = std::numeric_limits<int>::max();
    do {
        while (sum - nums[l] < target && r < nums.size()) {
            sum += nums[r++];
            if (sum >= target && r - l < minLen) {
                minLen = r - l;
            }
        }
        while (sum - nums[l] >= target) {
            sum -= nums[l++];
        }
        if (r - l < minLen) {
            minLen = r - l;
        }
    } while (r < nums.size());
    return sum < target ? 0 : minLen;
}