#include "15__3sum.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <cstddef>
#include <unordered_set>
#include <vector>

#include "../test_utils.hpp"

typedef std::vector<int> TestCase;

void sort_answer(vector<vector<int>>& ans) {
    std::sort(ans.begin(), ans.end(), [](vector<int>& a, vector<int>& b) {
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        if (a[0] < b[0]) {
            return true;
        }
        if (a[1] < b[1]) {
            return true;
        }
        if (a[2] < b[2]) {
            return true;
        }
        return false;
    });
}

struct AnsHashing {
    size_t operator()(const std::vector<int>& data) const {
        std::size_t seed = data.size();
        for (int i : data) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

void test__3sum(TestCase& _case) {
    unordered_set<vector<int>, AnsHashing> ans_set;
    for (int i = 0; i < _case.size(); ++i) {
        for (int j = 0; j < _case.size(); ++j) {
            for (int k = 0; k < _case.size(); ++k) {
                if (!(i < j && j < k)) {
                    continue;
                }
                int a = _case[i];
                int b = _case[j];
                int c = _case[k];
                if (a + b + c == 0) {
                    std::vector<int> v{a, b, c};
                    std::sort(v.begin(), v.end());
                    ans_set.insert(v);
                }
            }
        }
    }
    vector<vector<int>> ans(ans_set.begin(), ans_set.end());

    sort_answer(ans);
    auto myAns = threeSum(_case);

    sort_answer(myAns);
    std::cout << _case << std::endl;
    EXPECT_EQ(ans, myAns);
}

TEST(leetcode, _3sum) {
    std::vector<TestCase> cases{{-1, 0, 1, 2, -1, -4}, {0, 1, 1}, {0, 0, 0}};

    for (TestCase& c : cases) {
        test__3sum(c);
    }
}
