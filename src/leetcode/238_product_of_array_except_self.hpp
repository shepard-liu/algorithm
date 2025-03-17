// https://leetcode.cn/problems/product-of-array-except-self/ Product of Array
// Except Self
#include <cstddef>
#include <vector>
using namespace std;

inline vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    std::vector<int> ans(n, 1);

    int forward = 1, backward = 1;
    for (int i = 0; i < n; ++i) {
        int backIdx = n - 1 - i;
        forward *= nums[i];
        backward *= nums[backIdx];

        if (i + 1 <= n - 1) {
            ans[i + 1] *= forward;
        }
        if (backIdx - 1 >= 0) {
            ans[backIdx - 1] *= backward;
        }
    }

    return ans;
}