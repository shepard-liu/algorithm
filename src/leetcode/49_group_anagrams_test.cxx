#include "49_group_anagrams.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<std::vector<string>, std::vector<vector<string>>> TestCase;

string sort_string(const string& s) {
    string sorted = s;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}

void sort_answer(vector<vector<string>>& ans) {
    for (auto& g : ans) {
        std::sort(g.begin(), g.end());
    }
    std::sort(ans.begin(), ans.end());
}

void test_group_anagrams(TestCase& c) {
    auto [strs, ans] = c;

    sort_answer(ans);
    auto myAns = groupAnagrams(strs);
    sort_answer(myAns);

    EXPECT_EQ(ans, myAns);
}

TEST(leetcode, group_anagrams) {
    std::vector<TestCase> cases{
        {{"eat", "tea", "tan", "ate", "nat", "bat"},
         {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}},
        {{""}, {{""}}},
        {{"a"}, {{"a"}}}};

    for (TestCase& c : cases) {
        test_group_anagrams(c);
    }
}
