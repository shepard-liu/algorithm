// https://leetcode.cn/problems/subarray-sum-equals-k/ Subarray Sum Equals K
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define DBG(x) std::cout << #x << " = " << x << endl;

int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            if (sum == k) {
                ans++;
            }
        }
    }
    return ans;
}