// https://leetcode.cn/problems/search-insert-position/ Search Insert Position
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    return std::distance(nums.begin(),
                         std::lower_bound(nums.begin(), nums.end(), target));
}