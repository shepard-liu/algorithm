// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/ Letter
// Combinations of a Phone Number
#include <string>
#include <vector>
using namespace std;

inline void dfs(string& digits, vector<vector<char>>& mapping, int i,
                string path, vector<string>& ans) {
    if (i == digits.size()) {
        ans.push_back(path);
        return;
    }

    char c = digits[i];
    int idx = c - '2';
    const vector<char>& chars = mapping[idx];
    for (int k = 0; k < chars.size(); ++k) {
        dfs(digits, mapping, i + 1, path + chars[k], ans);
    }
}

inline vector<string> letterCombinations(string digits) {
    vector<vector<char>> mapping{{'a', 'b', 'c'}, {'d', 'e', 'f'},
                                 {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                 {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                 {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    vector<string> ans;
    dfs(digits, mapping, 0, "", ans);
    return ans.size() == 1 ? std::vector<string>{} : ans;
}