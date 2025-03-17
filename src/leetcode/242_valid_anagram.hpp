// https://leetcode.cn/problems/valid-anagram/ Valid Anagram
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

inline bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    std::vector<int> counts(26, 0);
    for (auto c : s) {
        counts[int(c - 'a')]++;
    }

    for (auto c : t) {
        int count = --counts[int(c - 'a')];
        if (count < 0) {
            return false;
        }
    }
    return true;
}
