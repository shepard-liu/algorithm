#include "290_word_pattern.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::tuple<string, string, bool> TestCase;

void test_word_pattern(TestCase& c) {
    auto [pattern, s, ans] = c;
    auto myAns = wordPattern(pattern, s);
    EXPECT_EQ(ans, myAns);
}

TEST(leetcode, word_pattern) {
    std::vector<TestCase> cases{{"abc", "dog cat dog", false},
                                {"abba", "dog dog dog dog", false},
                                {
                                    "abba",
                                    "dog cat cat dog",
                                    true,
                                },
                                {"aba", "cat cat cat dog", false},
                                {"abc", "dog cat dog", false},
                                {"abba", "dog cat cat fish", false},
                                {"aaaa", "dog cat cat dog", false}};

    for (TestCase& c : cases) {
        test_word_pattern(c);
    }
}
