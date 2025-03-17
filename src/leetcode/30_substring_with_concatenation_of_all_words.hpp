// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
// Substring with Concatenation of All Words
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

inline vector<int> findSubstring(string s, vector<string>& words) {
    int nWords = words.size();
    int wordLen = words[0].length();

    std::unordered_map<string, int> counts;
    for (auto& w : words) {
        counts.try_emplace(w, 0).first->second++;
    }

    std::vector<std::pair<string, int>> wordsWithCount;
    wordsWithCount.reserve(counts.size());
    std::copy(counts.begin(), counts.end(), std::back_inserter(wordsWithCount));

    std::vector<int> indexMap(s.size(), -1);

    for (size_t i = 0; i < wordsWithCount.size(); ++i) {
        string word = wordsWithCount[i].first;
        size_t pos = s.find(word, 0);
        while (pos != string::npos) {
            indexMap[pos] = i;
            pos = s.find(word, pos + 1);
        }
    }

    if (indexMap.size() == 0) {
        return {};
    }

    vector<int> ans;

    vector<int> visitCountTmpl(wordsWithCount.size(), 0);
    for (int i = 0; i < wordsWithCount.size(); ++i) {
        visitCountTmpl[i] = wordsWithCount[i].second;
    }

    for (int i = 0; i < indexMap.size(); ++i) {
        if (indexMap[i] == -1) {
            continue;
        }
        int count = nWords;
        vector<int> visitCount(visitCountTmpl);
        for (int j = i; j < i + nWords * wordLen && j < indexMap.size();
             j += wordLen) {
            int wordIdx = indexMap[j];
            if (wordIdx == -1 || visitCount[wordIdx] == 0) {
                break;
            }
            visitCount[wordIdx]--;
            count--;
        }

        if (count == 0) {
            ans.push_back(i);
        }
    }

    return ans;
}