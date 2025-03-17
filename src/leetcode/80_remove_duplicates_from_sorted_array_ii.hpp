// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/ Remove
// Duplicates from Sorted Array II
#include <cstddef>
#include <vector>
using namespace std;

inline int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }

    int count = 1;
    int last = nums[0];
    int k = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == last) {
            count++;
        } else {
            count = 1;
            last = nums[i];
        }

        if (count > 2) {
            continue;
        }
        nums[k++] = last;
    }

    return k;
}