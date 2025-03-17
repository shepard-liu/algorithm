// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/ Find
// Minimum in Rotated Sorted Array
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int impl(vector<int>& nums, int left, int right) {
    if (left + 1 == right) {
        return nums[left];
    }

    int mid = (left + right) / 2;
    int numMid = nums[mid];
    int numLeft = nums[left];

    if (numMid < numLeft) {
        if (mid - 1 >= 0 && numMid < nums[mid - 1]) {
            return numMid;
        }
        return impl(nums, left, mid);
    } else {
        return impl(nums, mid, right);
    }
}

inline int findMin(vector<int>& nums) {
    return min(nums[0], impl(nums, 0, nums.size()));
}
