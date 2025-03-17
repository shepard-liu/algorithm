// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
// Minimum Number of Arrows to Burst Balloons
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline int findMinArrowShots(vector<vector<int>>& points) {
    std::sort(
        points.begin(), points.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

    int minArrows = 0;
    for (int i = 0; i < points.size(); ++i) {
        int l{points[i][0]}, r{points[i][1]};
        minArrows++;
        int j = i + 1;
        while (j < points.size()) {
            int s = points[j][0];
            int t = points[j][1];

            l = std::max(l, s);
            r = std::min(r, t);
            if (l > r) {
                break;
            }
            ++j;
        }
        i = j - 1;
    }

    return minArrows;
}