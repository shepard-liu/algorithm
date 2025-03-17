#include "373_find_k_pairs_with_smallest_sums.hpp"

#include <algorithm>
#include <tuple>
#include <vector>

#include "../test_utils.hpp"
typedef tuple<vector<int>, vector<int>, int> TestCase;

void test_find_k_pairs_with_smallest_sums(TestCase& c) {
    auto [nums1, nums2, k] = c;
    std::vector<TupleType> pairs;

    auto myAns = kSmallestPairs(nums1, nums2, k);

    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            pairs.emplace_back(nums1[i] + nums2[j], nums1[i], nums2[j]);
        }
    }

    std::sort(pairs.begin(), pairs.end(),
              [](const TupleType& a, const TupleType& b) {
                  return get<0>(a) < get<0>(b);
              });
    vector<vector<int>> ans;
    ans.reserve(k);

    for (auto [sum, n1, n2] : pairs) {
        ans.push_back({n1, n2});
        k--;
        if (k == 0) {
            break;
        }
    }

    EXPECT_EQ(ans, myAns);
}

TEST(leetcode, find_k_pairs_with_smallest_sums) {
    TestCase c1{{1, 2, 4, 5, 6}, {3, 5, 7, 9}, 20};
    std::vector<TestCase> cases{c1};

    for (TestCase& c : cases) {
        test_find_k_pairs_with_smallest_sums(c);
    }
}
