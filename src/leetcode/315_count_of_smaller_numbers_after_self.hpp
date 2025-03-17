// https://leetcode.cn/problems/count-of-smaller-numbers-after-self/ Count of
// Smaller Numbers After Self
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

inline vector<int> countSmaller(vector<int>& nums) {
    std::vector<int> indexes(nums.size(), 0);
    std::iota(indexes.begin(), indexes.end(), 0);
    std::sort(indexes.begin(), indexes.end(),
              [&](const int& a, const int& b) { return nums[a] < nums[b]; });
    vector<int> ans(nums.size(), 0);
    int count = 0;
    for (auto& i : indexes) {
        ans[i] = count;
        count++;
    }
    return ans;
}