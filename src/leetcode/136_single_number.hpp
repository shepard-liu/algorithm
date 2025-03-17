// https://leetcode.cn/problems/single-number/ Single Number
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

inline int singleNumber(vector<int>& nums) {
    int n = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        n ^= nums[i];
    }
    return n;
}