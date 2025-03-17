#include "162_find_peak_element.hpp"

#include <iostream>
#include <vector>

#include "../test_utils.hpp"
typedef vector<int> TestCase;

void test_find_peak_element(TestCase& c) {
    auto myAns = findPeakElement(c);
    std::cout << myAns << ": " << c[myAns];
}

TEST(leetcode, find_peak_element) {
    std::vector<TestCase> cases{
        {1, 2, 3, 4, 3, 2, 1, -1, -5, -10, 1, 2, 3, 4, 5}};

    for (TestCase& c : cases) {
        test_find_peak_element(c);
    }
}
