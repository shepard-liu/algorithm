// https://leetcode.cn/problems/palindrome-number/ Palindrome Number
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    vector<int> digits;
    while (x != 0) {
        digits.push_back(x % 10);
        x /= 10;
    }

    for (int i = 0; i < digits.size() / 2; ++i) {
        if (digits[i] != digits[digits.size() - i - 1]) {
            return false;
        }
    }
    return true;
}