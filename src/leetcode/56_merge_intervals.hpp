// https://leetcode.cn/problems/merge-intervals/ Merge Intervals
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;

    std::sort(intervals.begin(), intervals.end(),
              [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

    for (int i = 0; i < intervals.size(); ++i) {
        int l{intervals[i][0]}, r{intervals[i][1]};
        int j = i + 1;
        while (j < intervals.size()) {
            int s = intervals[j][0], t = intervals[j][1];
            if (r >= s) {
                r = std::max(r, t);
                ++j;
            } else {
                break;
            }
        }

        ans.push_back({l, r});
        i = j - 1;
    }

    return ans;
}