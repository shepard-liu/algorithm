// https://leetcode.cn/problems/permutations/ Permutations
#include <cstddef>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int NoData = std::numeric_limits<int>::max();

inline int64_t factorial(int64_t n) {
    if (n == 1) {
        return 1;
    }
    return factorial(n - 1) * n;
}

inline void dfs(vector<int>& nums, int i, vector<int> res,
                vector<vector<int>>& ans) {
    int tmp = nums[i];
    res.push_back(tmp);
    nums[i] = NoData;
    int count = 0;
    for (size_t j = 0; j < nums.size(); ++j) {
        if (nums[j] != NoData) {
            count++;
            dfs(nums, j, res, ans);
        }
    }
    if (count == 0) {
        ans.push_back(res);
    }
    nums[i] = tmp;
}

inline vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    ans.reserve(factorial(nums.size()));
    vector<int> res{};
    res.reserve(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        dfs(nums, i, res, ans);
    }
    return ans;
}