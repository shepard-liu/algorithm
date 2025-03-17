#include "57_insert_interval.hpp"

#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "../test_utils.hpp"

typedef std::tuple<vector<vector<int>>, vector<int>, vector<vector<int>>>
    TestCase;

void test_insert_interval(TestCase& c) {
    auto [intervals, newInterval, ans] = c;
    std::cout << "intervals:\n"
              << intervals << "\nnewInterval:\n"
              << newInterval << std::endl;
    auto myAns = insert(intervals, newInterval);
    EXPECT_EQ(myAns, ans);
}

TEST(leetcode, insert_interval) {
    std::vector<TestCase> cases{{{{1, 5}}, {6, 8}, {{1, 5}, {6, 8}}},
                                {{{1, 5}}, {0, 3}, {{0, 5}}},
                                {{{1, 3}, {6, 9}}, {2, 5}, {{1, 5}, {6, 9}}},
                                {{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}},
                                 {4, 8},
                                 {{1, 2}, {3, 10}, {12, 16}}},
                                {{{1, 5}}, {1, 7}, {{1, 7}}}};

    for (TestCase& c : cases) {
        test_insert_interval(c);
    }
}
