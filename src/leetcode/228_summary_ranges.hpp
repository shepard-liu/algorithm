// https://leetcode.cn/problems/summary-ranges/ Summary Ranges
#include <string>
#include <vector>
using namespace std;

inline vector<string> summaryRanges(vector<int>& nums) {
    if (nums.size() == 0) {
        return {};
    }
    vector<string> ans;

    int start = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int n = nums[i];
        int last = nums[i - 1];
        if (n != last + 1) {
            if (start == last) {
                ans.emplace_back(std::to_string(start));
            } else {
                ans.emplace_back(std::to_string(start) + "->" +
                                 std::to_string(last));
            }
            start = n;
        }
    }

    int last = nums.back();

    if (start == last) {
        ans.emplace_back(std::to_string(start));
    } else {
        ans.emplace_back(std::to_string(start) + "->" + std::to_string(last));
    }

    return ans;
}