// https://leetcode.cn/problems/plus-one/ Plus One
#include <string>
#include <vector>
using namespace std;

inline vector<int> plusOne(vector<int>& digits) {
    int carry = 0;
    for (int i = digits.size() - 1; i >= 0; --i) {
        int sum = carry + digits[i] + (i == digits.size() - 1 ? 1 : 0);
        digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry == 1) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}