#include "215_kth_largest_element_in_an_array.hpp"

#include <vector>

#include "../test_utils.hpp"
typedef vector<int> TestCase;

void test_kth_largest_element_in_an_array(TestCase& c) {
    auto myAns = findKthLargest(c, 3);
    std::cout << "myAns: " << myAns << std::endl;
}

TEST(leetcode, kth_largest_element_in_an_array) {
    std::vector<TestCase> cases{{3, 2, 1, 5, 6, 4},
                                {-1, 8, 4, 3, 8, 1, 2, 1, 5, 8, 8}};

    for (TestCase& c : cases) {
        test_kth_largest_element_in_an_array(c);
    }
}
