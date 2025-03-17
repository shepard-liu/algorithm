// https://leetcode.cn/problems/ransom-note/ Ransom Note
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

inline bool canConstruct(string ransomNote, string magazine) {
    std::unordered_multiset<char> charset;
    std::unordered_multiset<char> targetset;

    for (auto c : magazine) {
        charset.insert(c);
    }

    for (auto c : ransomNote) {
        targetset.insert(c);
        if (targetset.count(c) > charset.count(c)) {
            return false;
        }
    }

    return true;
}