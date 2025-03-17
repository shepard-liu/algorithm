#include "399_evaluate_division.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "../test_utils.hpp"
typedef std::tuple<vector<vector<string>>, vector<double>,
                   vector<vector<string>>, vector<double>>
    TestCase;

void test_evaluate_division(TestCase& c) {
    auto [eqs, values, queries, ans] = c;
    auto myAns = calcEquation(eqs, values, queries);
    std::cout << myAns;
    std::cout << "equations: " << eqs << std::endl;
    std::cout << "values: " << values << std::endl;
    std::cout << "queries: " << queries << std::endl;
    EXPECT_EQ(ans.size(), myAns.size());
    for (int i = 0; i < ans.size(); ++i) {
        EXPECT_NEAR(myAns[i], ans[i], 1e-5);
    }
}

TEST(leetcode, evaluate_division) {
    TestCase c1{{{"a", "b"}, {"b", "c"}},
                {2.0, 3.0},
                {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}},
                {6.00000, 0.50000, -1.00000, 1.00000, -1.00000}};

    TestCase c2{{{"a", "b"}, {"b", "c"}, {"bc", "cd"}},
                {1.5, 2.5, 5.0},
                {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}},
                {3.75000, 0.40000, 5.00000, 0.20000}};

    TestCase c3{{{"a", "b"}},
                {0.5},
                {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}},
                {0.50000, 2.00000, -1.00000, -1.00000}};

    TestCase c4{{{"a", "b"},
                 {"a", "c"},
                 {"d", "e"},
                 {"d", "f"},
                 {"a", "d"},
                 {"aa", "bb"},
                 {"aa", "cc"},
                 {"dd", "ee"},
                 {"dd", "ff"},
                 {"aa", "dd"},
                 {"a", "aa"}},
                {2.0, 3.0, 4.0, 5.0, 7.0, 5.0, 8.0, 9.0, 3.0, 2.0, 2.0},
                {{"ff", "a"}},
                {0.0833333333333333333}};

    TestCase c5{{{"a", "b"},
                 {"a", "c"},
                 {"d", "e"},
                 {"d", "f"},
                 {"a", "d"},
                 {"aa", "bb"},
                 {"aa", "cc"},
                 {"dd", "ee"},
                 {"dd", "ff"},
                 {"aa", "dd"},
                 {"a", "aa"}},
                {2.0, 3.0, 4.0, 5.0, 7.0, 5.0, 8.0, 9.0, 3.0, 2.0, 2.0},
                {{"ff", "a"}},
                {}};

    TestCase c6{{{"x1", "x2"},
                 {"x3", "x4"},
                 {"x2", "x4"},
                 {"x10", "x20"},
                 {"x30", "x40"},
                 {"x20", "x40"},
                 {"x4", "x40"}},
                {2.0, 3.0, 5.0, 7.0, 11.0, 13.0, 19.0},
                {{"x1", "x10"}},
                {2.08791}};

    std::vector<TestCase> cases{c6};

    for (TestCase& c : cases) {
        test_evaluate_division(c);
    }
}
