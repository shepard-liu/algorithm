// https://leetcode.cn/problems/insert-interval/ Insert Interval
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

inline vector<vector<int>> insert(vector<vector<int>>& intervals,
                                  vector<int>& newInterval) {
    if (intervals.size() == 0) {
        return {newInterval};
    }
    int pos = std::distance(
        intervals.begin(),
        std::lower_bound(
            intervals.begin(), intervals.end(), newInterval[0],
            [](const vector<int>& elem, int ins) { return elem[0] <= ins; }));

    int start = std::max(0, pos - 1);
    int end = start;

    int l{newInterval[0]}, r{newInterval[1]};

    // try merge start
    if (start == pos - 1 && intervals[start][1] >= l) {
        l = intervals[start][0];
    } else {
        start = pos;
        end = pos;
    }

    while (end < intervals.size()) {
        int s = intervals[end][0];
        int t = intervals[end][1];
        if (r >= s) {
            r = std::max(r, t);
            ++end;
        } else if (end >= pos) {
            break;
        }
    }

    if (start == end) {
        intervals.insert(intervals.begin() + pos, newInterval);
    } else {
        intervals[start] = {l, r};
        intervals.erase(intervals.begin() + start + 1, intervals.begin() + end);
    }

    return intervals;
}