// https://leetcode.cn/problems/remove-element/ Remove Element

#include <type_traits>
#include <vector>
using namespace std;

inline int removeElement(vector<int>& nums, int val) {
    int end = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (nums[i] == val) {
            std::swap(nums[i], nums[end]);
            --end;
        }
    }
    return end + 1;
}