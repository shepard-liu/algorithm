#include "76_minimum_window_substring.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <limits>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<string, string> TestCase;

void test_minimum_window_substring(TestCase& c) {
    auto [s, t] = c;
    int minLen = std::numeric_limits<int>::max();
    int minL{}, minR{};
    unordered_map<char, int> chars;
    for (auto& c : t) {
        chars.try_emplace(c, 0).first->second++;
    }

    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + t.size(); j <= s.size(); ++j) {
            unordered_map<char, int> charCount;
            int total = 0;
            for (auto [key, _] : chars) {
                charCount[key] = 0;
            }

            for (int k = i; k < j; ++k) {
                if (charCount.find(s[k]) != charCount.end()) {
                    if (charCount[s[k]]++ < chars[s[k]]) {
                        total++;
                    }
                }
            }
            if (total == t.size()) {
                minLen = std::min(minLen, j - i);
                minL = i;
                minR = j;
                break;
            }
        }
    }

    auto ans = s.substr(minL, minR - minL);
    auto myAns = minWindow(s, t);
    EXPECT_EQ(ans, myAns) << "s: " << s << "; t: " << t;
}

TEST(leetcode, minimum_window_substring) {
    std::vector<TestCase> cases{{"bbaa", "aba"}, {"abc", "b"},
                                {"abc", "a"},    {"abc", "c"},
                                {"ab", "a"},     {"ADOBECODEBANC", "ABC"},
                                {"a", "a"},      {"a", "aa"}};

    for (TestCase& c : cases) {
        test_minimum_window_substring(c);
    }
}
