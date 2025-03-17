// https://leetcode.cn/problems/longest-common-prefix/ Longest Common Prefix
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

inline string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) {
        return strs[0];
    }
    std::string prefix;
    size_t i = 0;
    while (true) {
        for (size_t j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != strs[j - 1][i]) {
                return prefix;
            }
        }
        prefix += strs[0][i];
        ++i;
    }
    return prefix;
}