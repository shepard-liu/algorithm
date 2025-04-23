#include "239_sliding_window_maximum.hpp"

#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<vector<int>, int> TestCase;

void test_sliding_window_maximum(TestCase& c) {
    auto [nums, k] = c;
    auto myAns = maxSlidingWindow(nums, k);
    cout << myAns << endl;
}

TEST(leetcode, sliding_window_maximum) {
    TestCase c1{{1, 3, -1, -3, 5, 3, 6, 7}, 3};

    TestCase c2{{1}, 1};

    TestCase c3{{1, -1}, 1};
    std::vector<TestCase> cases{c1, c2, c3};

    for (TestCase& c : cases) {
        test_sliding_window_maximum(c);
    }
}
