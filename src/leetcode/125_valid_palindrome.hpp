// https://leetcode.cn/problems/valid-palindrome/ Valid Palindrome
#include <cctype>
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

inline bool isPalindrome(string s) {
    size_t i = 0, j = s.size() - 1;
    while (i < j) {
        char a = std::tolower(s[i]);
        char b = std::tolower(s[j]);
        if (std::isalpha(a) == false && std::isdigit(a) == false) {
            ++i;
            continue;
        }
        if (std::isalpha(b) == false && std::isdigit(b) == false) {
            --j;
            continue;
        }
        if (a != b) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}