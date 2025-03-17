#include "151_reverse_words_in_a_string.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<string, string> TestCase;

void test_reverse_words_in_a_string(TestCase& c) {
    string ans = reverseWords(c.first);
    EXPECT_EQ(ans, c.second);
}

TEST(leetcode, reverse_words_in_a_string) {
    std::vector<TestCase> cases{{"the sky is blue", "blue is sky the"},
                                {"  hello world  ", "world hello"},
                                {"", ""}};

    for (TestCase& c : cases) {
        test_reverse_words_in_a_string(c);
    }
}
