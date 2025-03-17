// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
// Find First and Last Position of Element in Sorted Array
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

inline vector<int> searchRange(vector<int>& nums, int target) {
    int l = std::distance(nums.begin(),
                          std::lower_bound(nums.begin(), nums.end(), target));
    int r = std::distance(nums.begin(),
                          std::upper_bound(nums.begin(), nums.end(), target));
    return l == nums.size()    ? vector<int>({-1, -1})
           : nums[l] == target ? vector<int>({l, r - 1})
                               : vector<int>({-1, -1});
}