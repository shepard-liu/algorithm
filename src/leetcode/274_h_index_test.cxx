#include "274_h_index.hpp"

#include <vector>

#include "../test_utils.hpp"

typedef std::vector<int> TestCase;

void test_h_index(TestCase& c) { std::cout << hIndex(c) << std::endl; }

TEST(leetcode, h_index) {
    std::vector<TestCase> cases{
        {3, 0, 6, 1, 5}, {1, 2, 3, 4, 5}, {0}, {0, 1}, {10, 10, 10}};

    for (TestCase& c : cases) {
        test_h_index(c);
    }
}
