// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/ Remove
// Duplicates from Sorted Array
#include <cstddef>
#include <vector>
using namespace std;

inline int removeDuplicates(vector<int>& nums) {
    int k = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i >= 1 && nums[i] == nums[i - 1]) {
            continue;
        }
        nums[k++] = nums[i];
    }
    return k;
}