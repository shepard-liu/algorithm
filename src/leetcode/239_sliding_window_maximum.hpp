// https://leetcode.cn/problems/sliding-window-maximum/ Sliding Window Maximum
#include <deque>
#include <string>
#include <utility>
#include <vector>
using namespace std;

inline vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<pair<int, int>> q;

    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
        auto n = nums[i];
        while (!q.empty() && i - q.front().second >= k) {
            q.pop_front();
        }
        while (!q.empty() && q.back().first < n) {
            q.pop_back();
        }
        q.push_back({n, i});
        if (i < k - 1) {
            continue;
        }
        ans.push_back(q.front().first);
    }

    return ans;
}