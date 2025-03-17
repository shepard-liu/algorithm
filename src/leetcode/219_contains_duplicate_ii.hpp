// https://leetcode.cn/problems/contains-duplicate-ii/ Contains Duplicate II
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

inline bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> lastIndexes{};
    lastIndexes.reserve(nums.size());

    for (int i = 0; i < nums.size(); ++i) {
        int n = nums[i];
        auto it = lastIndexes.find(n);
        if (it != lastIndexes.end() && (i - it->second) <= k) {
            return true;
        }
        lastIndexes[n] = i;
    }

    return false;
}