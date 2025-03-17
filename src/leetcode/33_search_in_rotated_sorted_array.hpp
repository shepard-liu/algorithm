// https://leetcode.cn/problems/search-in-rotated-sorted-array/ Search in
// Rotated Sorted Array
#include <string>
#include <vector>
using namespace std;

inline int impl(vector<int>& nums, int left, int right, int target) {
    if (left + 1 == right) {
        return nums[left] == target ? left : -1;
    }

    int mid = (left + right) / 2;
    int numLeft = nums[left];
    int numRight = nums[right - 1];
    int numMid = nums[mid];

    if (numMid == target) {
        return mid;
    }
    if (numLeft == target) {
        return left;
    }
    if (numRight == target) {
        return right - 1;
    }

    if (numMid > numLeft) {
        if (numLeft < target && target < numMid) {
            return impl(nums, left, mid, target);
        } else {
            return impl(nums, mid, right, target);
        }
    } else {
        if (numMid < target && target < numRight) {
            return impl(nums, mid, right, target);
        } else {
            return impl(nums, left, mid, target);
        }
    }
}

inline int search(vector<int>& nums, int target) {
    return impl(nums, 0, nums.size(), target);
}