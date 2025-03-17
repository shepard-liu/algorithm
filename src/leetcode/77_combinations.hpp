// https://leetcode.cn/problems/combinations/ Combinations
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline uint64_t factorial(uint64_t n) {
    uint64_t ans = 1;
    for (uint64_t i = 2; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

inline uint64_t binomial(uint64_t n, uint64_t r) {
    if (r >= std::ceil(n / 2)) {
        r = n - r;
    }

    uint64_t e = 1;
    for (uint64_t i = n - r + 1; i <= n; ++i) {
        e *= i;
    }

    return e / factorial(r);
}

inline void dfs(vector<vector<int>>& ans, int depth, int from, int to,
                vector<int>& comb) {
    if (depth == 0) {
        ans.push_back(comb);
        return;
    }

    for (int nextVal = from; nextVal < to; ++nextVal) {
        comb.push_back(nextVal);
        dfs(ans, depth - 1, nextVal + 1, to, comb);
        comb.pop_back();
    }
}

inline vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> comb;
    comb.reserve(k);

    dfs(ans, k, 0, n, comb);
    return ans;
}