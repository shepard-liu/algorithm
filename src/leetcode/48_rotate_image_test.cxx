#include "48_rotate_image.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<vector<vector<int>>, vector<vector<int>>> TestCase;

void test_rotate_image(TestCase& c) {
    auto [input, ans] = c;
    auto myAns = input;
    rotate(myAns);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, rotate_image) {
    std::vector<TestCase> cases{
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}},
        {{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
         {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}}};

    for (TestCase& c : cases) {
        test_rotate_image(c);
    }
}
