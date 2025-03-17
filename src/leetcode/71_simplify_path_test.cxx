#include "71_simplify_path.hpp"

#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<string, string> TestCase;

void test_simplify_path(TestCase& c) {
    auto [str, ans] = c;
    auto myAns = simplifyPath(str);
    EXPECT_EQ(myAns, ans) << str;
}

TEST(leetcode, simplify_path) {
    std::vector<TestCase> cases{
        {"/home/", "/home"},
        {"/home//foo/", "/home/foo"},
        {"/home/user/Documents/../Pictures", "/home/user/Pictures"},
        {"/../", "/"},
        {"/.../a/../b/c/../d/./", "/.../b/d"}};

    for (TestCase& c : cases) {
        test_simplify_path(c);
    }
}
