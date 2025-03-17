// https://leetcode.cn/problems/minimum-window-substring/ Minimum Window
// Substring
#include <algorithm>
#include <limits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

inline string minWindow(string s, string t) {
    int l = 0, r = 0;
    int wndSize = t.size();
    unordered_map<char, int> chars;
    for (auto& c : t) {
        chars.try_emplace(c, 0).first->second++;
    }

    int total = 0;
    int minLen = std::numeric_limits<int>::max();
    int minL{}, minR{};
    unordered_map<char, int> charCount;
    for (auto [key, _] : chars) {
        charCount[key] = 0;
    }

    while (r < s.size()) {
        char c = s[r++];
        if (charCount.find(c) != charCount.end()) {
            if (charCount[c]++ < chars[c]) {
                total++;
            }

            while (true) {
                char lc = s[l];
                if (charCount.find(lc) == charCount.end()) {
                    l++;
                } else if (charCount[lc] <= chars[lc]) {
                    break;
                } else {
                    charCount[lc]--;
                    l++;
                }
            }
        }

        if (total >= wndSize && r - l < minLen) {
            minLen = r - l;
            minL = l;
            minR = r;
        }
    }

    return s.substr(minL, minR - minL);
}