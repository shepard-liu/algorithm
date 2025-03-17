#include "30_substring_with_concatenation_of_all_words.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "../test_utils.hpp"

typedef std::tuple<string, vector<string>, vector<int>> TestCase;

void test_substring_with_concatenation_of_all_words(TestCase& c) {
    auto [s, words, ans] = c;

    auto myAns = findSubstring(s, words);

    std::cout << s << ". Words: " << words << std::endl;

    std::sort(ans.begin(), ans.end());
    std::sort(myAns.begin(), myAns.end());

    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, substring_with_concatenation_of_all_words) {
    std::vector<TestCase> cases{
        {"barfoothefoobarman", {"foo", "bar"}, {0, 9}},
        {"wordgoodgoodgoodbestword", {"word", "good", "best", "word"}, {}},
        {"barfoofoobarthefoobarman", {"bar", "foo", "the"}, {6, 9, 12}}};

    for (TestCase& c : cases) {
        test_substring_with_concatenation_of_all_words(c);
    }
}
