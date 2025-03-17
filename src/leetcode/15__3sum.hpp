// https://leetcode.cn/problems/3sum/ 3Sum
#include <algorithm>
#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

inline vector<vector<int>> threeSum(vector<int>& nums) {
    std::unordered_map<int, std::vector<int>> hashes{};
    int n = nums.size();
    for (size_t i = 0; i < n; ++i) {
        hashes[nums[i]].push_back(i);
    }

    struct AnsHashing {
        size_t operator()(const std::vector<int>& data) const {
            std::size_t seed = data.size();
            for (int i : data) {
                seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    std::unordered_set<vector<int>, AnsHashing> ans_set{};
    std::unordered_set<int> first_visited{};
    for (int i = 0; i < n; ++i) {
        int a = nums[i];
        if (first_visited.find(a) != first_visited.end()) {
            continue;
        }
        first_visited.insert(a);
        int sum = 0 - a;
        for (int j = i + 1; j < n; ++j) {
            int b = nums[j];
            int c = sum - b;
            auto it = hashes.find(c);
            if (it == hashes.end()) {
                continue;
            }
            auto indexes = it->second;
            if (indexes.back() <= j) {
                continue;
            }
            std::vector<int> v{a, b, c};
            std::sort(v.begin(), v.end());
            ans_set.insert(v);
        }
    }

    return vector<vector<int>>(ans_set.begin(), ans_set.end());
}