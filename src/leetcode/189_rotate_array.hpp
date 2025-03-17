// https://leetcode.cn/problems/rotate-array/ Rotate Array
#include <cstddef>
#include <type_traits>
#include <vector>
using namespace std;

inline void rotate(vector<int>& nums, int k) {
    size_t n = nums.size();
    if (n == 0 || k % n == 0) {
        return;
    }

    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        int last = nums[i];
        size_t curIdx = (k + i) % n;
        size_t sum = 0;
        do {
            std::swap(nums[curIdx], last);
            curIdx = (curIdx + k) % n;
            sum += k;
            count++;
        } while (sum % n != 0);
        if (count == n) {
            break;
        }
    }
}