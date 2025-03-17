// https://leetcode.cn/problems/two-sum/ Two Sum
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

inline vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numset{};
    numset.reserve(nums.size());

    for (int i = 0; i < nums.size(); ++i) {
        int n = nums[i];
        auto it = numset.find(target - n);
        if (it != numset.end()) {
            return {i, it->second};
        }
        numset[n] = i;
    }

    return {};
}