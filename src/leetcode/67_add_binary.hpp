// https://leetcode.cn/problems/add-binary/ Add Binary
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

inline string addBinary(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1;
    string res;
    int carry = 0;
    while (i >= 0 && j >= 0) {
        int sum = carry + int(a[i] - '0') + int(b[j] - '0');
        carry = sum / 2;
        res.push_back(sum % 2 + '0');
        i--;
        j--;
    }

    while (i >= 0) {
        int sum = carry + int(a[i] - '0');
        carry = sum / 2;
        res.push_back(sum % 2 + '0');
        i--;
    }

    while (j >= 0) {
        int sum = carry + int(b[j] - '0');
        carry = sum / 2;
        res.push_back(sum % 2 + '0');
        j--;
    }

    if (carry == 1) {
        res.push_back('1');
    }

    std::reverse(res.begin(), res.end());
    return res;
}