// https://leetcode.cn/problems/zigzag-conversion/ Zigzag Conversion
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

inline string convert(string s, int numRows) {
    string ans;
    ans.reserve(s.size());
    size_t base = (numRows - 1) * 2;
    if (base == 0) {
        base = 1;
    }

    for (size_t i = 0; i < numRows; ++i) {
        size_t j = i;
        size_t inc = i * 2;
        while (j < s.size()) {
            if (i == 0 || i == numRows - 1) {
                ans.push_back(s[j]);
                j += base;
            } else {
                ans.push_back(s[j]);
                inc = base - inc;
                j += inc;
            }
        }
    }

    return ans;
}