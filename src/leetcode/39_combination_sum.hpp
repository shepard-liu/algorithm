// https://leetcode.cn/problems/combination-sum/ Combination Sum
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

inline void dfs(vector<vector<int>>& ans, int depth, int from, int to,
                vector<int>& candidates, vector<int>& comb, int sum) {
    if (sum == 0) {
        ans.push_back(comb);
        return;
    }
    if (sum < 0) {
        return;
    }

    for (int nextVal = from; nextVal < to; ++nextVal) {
        int canIdx = nextVal - depth;
        if (canIdx >= candidates.size()) {
            break;
        }
        int num = candidates[canIdx];
        comb.push_back(num);
        dfs(ans, depth + 1, nextVal + 1, to, candidates, comb, sum - num);
        comb.pop_back();
    }
}

inline vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int r = std::ceil(target / 2);
    int n = candidates.size();

    vector<vector<int>> ans{};
    vector<int> comb;

    dfs(ans, 0, 0, n + r - 1, candidates, comb, target);
    return ans;
}