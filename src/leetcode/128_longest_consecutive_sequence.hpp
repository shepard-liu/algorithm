// https://leetcode.cn/problems/longest-consecutive-sequence/ Longest
// Consecutive Sequence
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

inline int longestConsecutive(vector<int>& nums) {
    unordered_map<int, bool> visited;
    visited.reserve(nums.size());

    for (auto n : nums) {
        visited[n] = false;
    }

    int maxLen = 0;
    for (auto n : nums) {
        if (visited[n]) {
            continue;
        }
        int above = n + 1;
        unordered_map<int, bool>::iterator it = visited.find(above);
        while (it != visited.end()) {
            it->second = true;
            ++above;
            it = visited.find(above);
        }

        int below = n - 1;
        it = visited.find(below);
        while (it != visited.end()) {
            it->second = true;
            --below;
            it = visited.find(below);
        }

        int len = above - below - 1;
        if (maxLen < len) {
            maxLen = len;
        }
    }

    return maxLen;
}