// https://leetcode.cn/problems/single-number-ii/ Single Number II
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_multiset<int> set;
    set.reserve(nums.size());

    for (auto n : nums) {
        set.insert(n);
    }

    for (auto n : set) {
        if (set.count(n) == 1) {
            return n;
        }
    }
    return 0;
}