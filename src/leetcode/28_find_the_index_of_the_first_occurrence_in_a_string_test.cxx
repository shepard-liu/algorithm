#include "28_find_the_index_of_the_first_occurrence_in_a_string.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<string, string> TestCase;

void test_find_the_index_of_the_first_occurrence_in_a_string(TestCase& c) {
    size_t idx = c.first.find(c.second);
    int ans = -1;
    if (idx != std::string::npos) {
        ans = idx;
    }
    std::cout << c.first << ", " << c.second << std::endl;
    EXPECT_EQ(ans, strStr(c.first, c.second));
}

TEST(leetcode, find_the_index_of_the_first_occurrence_in_a_string) {
    std::vector<TestCase> cases{
        {"aaa", "aa"}, {"sadbutsad", "sad"}, {"leetcode", "leeto"}};

    for (TestCase& c : cases) {
        test_find_the_index_of_the_first_occurrence_in_a_string(c);
    }
}
