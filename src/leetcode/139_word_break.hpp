// https://leetcode.cn/problems/word-break/ Word Break
#include <algorithm>
#include <cstddef>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

inline bool canBreakFrom(string& s, vector<unordered_set<size_t>>& occurs,
                         vector<int>& dp, int start) {
    int n = s.size();
    if (start == n) {
        return true;
    }

    if (dp[start] != -1) {
        return dp[start];
    }

    if (occurs[start].size() == 0) {
        dp[start] = false;
        return false;
    }

    bool can = std::any_of(
        occurs[start].begin(), occurs[start].end(),
        [&](size_t end) { return canBreakFrom(s, occurs, dp, end); });
    dp[start] = can;
    return can;
}

inline bool wordBreak(string s, vector<string>& wordDict) {
    vector<unordered_set<size_t>> occurs(s.size(), unordered_set<size_t>());

    for (size_t i = 0; i < wordDict.size(); ++i) {
        string& word = wordDict[i];
        size_t pos{};
        do {
            pos = s.find(word, pos);
            if (pos == string::npos) {
                break;
            }
            occurs[pos].insert(pos + word.size());
            pos++;
        } while (true);
    }

    vector<int> dp(s.size(), -1);

    return canBreakFrom(s, occurs, dp, 0);
}