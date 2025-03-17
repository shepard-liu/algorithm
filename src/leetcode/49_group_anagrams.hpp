// https://leetcode.cn/problems/group-anagrams/ Group Anagrams
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

inline vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, int> groupMap;

    for (int i = 0; i < strs.size(); ++i) {
        string s = strs[i];
        std::sort(s.begin(), s.end());

        auto it = groupMap.find(s);
        if (it != groupMap.end()) {
            ans[it->second].push_back(strs[i]);
        } else {
            ans.push_back({strs[i]});
            groupMap[s] = ans.size() - 1;
        }
    }

    return ans;
}