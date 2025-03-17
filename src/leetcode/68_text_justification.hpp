// https://leetcode.cn/problems/text-justification/ Text Justification
#include <cstddef>
#include <string>
#include <vector>
using namespace std;

inline vector<string> fullJustify(vector<string>& words, size_t maxWidth) {
    size_t i = 0;
    std::vector<string> lines;
    while (i < words.size()) {
        size_t lineStart = i;
        size_t letterCount = words[i].size();
        size_t minSpan = words[i].size();
        i++;
        while (i < words.size()) {
            size_t nextSpan = minSpan + words[i].size() + 1;
            if (nextSpan <= maxWidth) {
                minSpan = nextSpan;
                letterCount += words[i].size();
            } else {
                break;
            }
            i++;
        }

        string line = words[lineStart];
        // last line
        if (i == words.size()) {
            for (size_t j = lineStart + 1; j < i; ++j) {
                line += ' ' + words[j];
            }
            line += std::string(maxWidth - line.size(), ' ');
        } else {
            size_t totalSpaces = maxWidth - letterCount;
            size_t numWords = i - lineStart;
            size_t numGaps = numWords - 1;
            size_t spacePerGap = numGaps == 0 ? 0 : totalSpaces / numGaps;
            size_t numOverflowGaps = totalSpaces - spacePerGap * numGaps;

            for (size_t j = 0; j < numWords - 1; ++j) {
                line += std::string(
                            j < numOverflowGaps ? spacePerGap + 1 : spacePerGap,
                            ' ') +
                        words[j + lineStart + 1];
            }
        }
        line += std::string(maxWidth - line.size(), ' ');
        lines.emplace_back(std::move(line));
    }
    return lines;
}