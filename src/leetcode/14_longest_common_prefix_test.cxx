#include "14_longest_common_prefix.hpp"

#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<std::vector<std::string>, std::string> TestCase;

void test_longest_common_prefix(TestCase& c) {
    auto ans = longestCommonPrefix(c.first);
    EXPECT_EQ(ans, c.second);
}

TEST(leetcode, longest_common_prefix) {
    std::vector<TestCase> cases{
        {{"flower", "flow", "flight"}, "fl"},
        {{"dog", "racecar", "car"}, ""},
        {{""}, ""},
        {{"abcsdawd", "abcsdawd", "abcsdawd", "abcsdawd"}, "abcsdawd"}};

    for (TestCase& c : cases) {
        test_longest_common_prefix(c);
    }
}
