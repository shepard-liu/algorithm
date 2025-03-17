// https://leetcode.cn/problems/container-with-most-water/ Container With Most
// Water
#include <vector>
using namespace std;

inline int maxArea(vector<int>& height) {
    int max = 0;
    size_t n = height.size();
    size_t i = 0, j = n - 1;
    while (i < j) {
        int area = std::min(height[i], height[j]) * (j - i);
        if (area > max) {
            max = area;
        }
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return max;
}