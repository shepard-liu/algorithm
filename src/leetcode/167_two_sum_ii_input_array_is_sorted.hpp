// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/ Two Sum II -
// Input Array Is Sorted
#include <vector>
using namespace std;

inline vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (i != j) {
        int a = numbers[i];
        int b = numbers[j];
        if (a + b > target) {
            j--;
            continue;
        } else if (a + b < target) {
            i++;
            continue;
        } else {
            return {i, j};
        }
    }
    return {};
}