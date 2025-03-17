// https://leetcode.cn/problems/isomorphic-strings/ Isomorphic Strings
#include <string>
#include <vector>
using namespace std;

inline bool isIsomorphic(string s, string t) {
    std::vector<int> charMap(256, -1);
    std::vector<int> inverseCharMap(256, -1);
    for (int i = 0; i < s.size(); ++i) {
        int source = s[i];
        int dest = t[i];
        if (charMap[source] == -1) {
            if (inverseCharMap[dest] == -1) {
                charMap[source] = dest;
                inverseCharMap[dest] = source;
            } else {
                return false;
            }
            continue;
        }
        if (dest != charMap[source]) {
            return false;
        }
    }
    return true;
}