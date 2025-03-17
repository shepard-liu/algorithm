#include "169_majority_element.hpp"

#include <vector>

#include "../test_utils.hpp"

typedef std::vector<int> TestCase;

void test_majority_element(TestCase& c) {
    int expected_majority_element = majorityElement(c);
    std::cout << "Array: " << c << std::endl;
    std::cout << "Ans: " << expected_majority_element << std::endl;
    int count = 0;
    for (int num : c) {
        if (num == expected_majority_element) {
            count++;
        }
    }
    ASSERT_GT(count, c.size() / 2);
}

TEST(leetcode, majority_element) {
    std::vector<TestCase> cases{
        {3, 2, 3},
        {2, 2, 1, 1, 1, 2, 2},
        {1, 1, 1, 1, 2, 2, 2},
        {1, 2, 3, 1, 1},
        {1, 1, 1, 2, 2, 2, 2, 2},
        {5, 5, 5, 5, 5, 1, 2, 3, 4},
        {6, 6, 6, 7, 7, 6, 6},
        {8, 8, 8, 8, 8, 8, 8, 8, 8},
        {9, 9, 9, 9, 9, 9, 9, 9, 1, 2, 3, 4, 5, 6, 7},
        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9}};

    for (TestCase& c : cases) {
        test_majority_element(c);
    }
}
