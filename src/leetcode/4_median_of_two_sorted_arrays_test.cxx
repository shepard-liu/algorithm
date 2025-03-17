#include "4_median_of_two_sorted_arrays.hpp"

#include <iostream>
#include <utility>
#include <vector>

#include "../test_utils.hpp"
typedef pair<vector<int>, vector<int>> TestCase;

void test_median_of_two_sorted_arrays(TestCase& c) {
    auto [nums1, nums2] = c;
    vector<int> merged{};
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i]);
            i++;
        } else {
            merged.push_back(nums2[j]);
            j++;
        }
    }
    while (i < nums1.size()) {
        merged.push_back(nums1[i++]);
    }
    while (j < nums2.size()) {
        merged.push_back(nums2[j++]);
    }
    int m = nums1.size(), n = nums2.size();

    std::cout << nums1 << '\n' << nums2 << std::endl;
    std::cout << "merged: " << merged << std::endl;
    auto myans = findMedianSortedArrays(nums1, nums2);

    double mid =
        (m + n) % 2 == 0
            ? (0.5 * double(merged[(m + n) / 2] + merged[(m + n) / 2 - 1]))
            : merged[(m + n) / 2];
    EXPECT_EQ(mid, myans);
    std::cout << "\n\n\n";
}

TEST(leetcode, median_of_two_sorted_arrays) {
    TestCase c1{{1, 3, 5, 7, 9}, {2, 4, 6, 8}};
    TestCase c2{{7, 8, 9, 10}, {2, 4, 6, 8}};
    TestCase c3{{7, 8, 9, 10}, {1, 3, 4, 5}};
    TestCase c4{{1}, {5, 6, 7, 8, 9}};
    TestCase c5{{0, 0}, {0, 0}};
    TestCase c6{{0, 0, 0, 0, 0}, {-1, 0, 0, 0, 0, 0, 1}};
    TestCase c7{{1, 3}, {2}};
    std::vector<TestCase> cases{c7};

    for (TestCase& c : cases) {
        test_median_of_two_sorted_arrays(c);
    }
}
