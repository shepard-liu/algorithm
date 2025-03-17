// https://leetcode.cn/problems/find-peak-element/ Find Peak Element
#include <limits>
#include <string>
#include <vector>
using namespace std;

inline int findPeak(vector<int>& nums, int l, int r) {
    if (l + 1 == r) {
        return l;
    }

    int mid = (l + r) / 2;
    int midNum = nums[mid];
    int midLeft = mid - 1 == -1 ? numeric_limits<int>::min() : nums[mid - 1];
    int midRight =
        mid + 1 == nums.size() ? numeric_limits<int>::min() : nums[mid + 1];

    if (midLeft > midNum) {
        return findPeak(nums, l, mid);
    } else if (midRight > midNum) {
        return findPeak(nums, mid, r);
    } else {
        return mid;
    }
}

inline int findPeakElement(vector<int>& nums) {
    return findPeak(nums, -1, nums.size());
}