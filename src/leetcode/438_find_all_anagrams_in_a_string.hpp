// https://leetcode.cn/problems/find-all-anagrams-in-a-string/ Find All Anagrams
// in a String
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

inline vector<int> findAnagrams(string s, string p) {
    vector<int> freqs(26, 0);

    for (auto c : p) {
        freqs[c - 'a']++;
    }

    vector<int> ans{};
    vector<int> counts(26, 0);
    for (int i = 0; i < s.size(); ++i) {
        counts[s[i] - 'a']++;
        if (i >= p.size()) {
            counts[s[i - p.size()] - 'a']--;
        }

        if (counts == freqs) {
            ans.push_back(i - p.size() + 1);
        }
    }

    return ans;
}