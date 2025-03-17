// https://leetcode.cn/problems/median-of-two-sorted-arrays/ Median of Two
// Sorted Arrays
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <vector>
using namespace std;

inline int IntMin = numeric_limits<int>::min();

inline double findMedian(vector<int>& nums1, vector<int>& nums2, int mid1,
                         int mid2) {
    int m = nums1.size(), n = nums2.size();
    int numMid1 = nums1[mid1], numMid2 = nums2[mid2];

    if ((m + n) % 2 == 1) {
        return std::max(nums1[mid1], nums2[mid2]);
    }
    int k1 = mid1 - 1, k2 = mid2 - 1;
    k1 = k1 >= 0 ? nums1[k1] : IntMin;
    k2 = k2 >= 0 ? nums2[k2] : IntMin;
    if (numMid1 > numMid2) {
        return 0.5 * (numMid1 + std::max(std::max(numMid2, k1), k2));
    } else {
        return 0.5 * (numMid2 + std::max(std::max(numMid1, k1), k2));
    }
}

inline double impl(vector<int>& nums1, vector<int>& nums2, int left1,
                   int right1, int left2, int right2) {
    int mid1 = (left1 + right1) / 2;
    int mid2 = (left2 + right2) / 2;

    int numMid1 = nums1[mid1];
    int numMid2 = nums2[mid2];

    if (left1 + 1 == right1 || left2 + 1 == right2) {
        return findMedian(nums1, nums2, mid1, mid2);
    }

    if (numMid1 > numMid2) {
        return impl(nums1, nums2, left1, mid1, mid2, right2);
    } else {
        return impl(nums1, nums2, mid1, right1, left2, mid2);
    }
}

inline double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    return impl(nums1, nums2, 0, nums1.size(), 0, nums2.size());
}

inline double findMedianSortedArrays_(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0) {
        return nums2.front();
    }
    if (nums2.size() == 0) {
        return nums1.front();
    }

    int m = nums1.size(), n = nums2.size();
    int l1{0}, l2{0}, r1 = m, r2 = n;

    do {
        int mid1 = (l1 + r1) / 2;
        int mid2 = (l2 + r2) / 2;
        int numMid1 = nums1[mid1];
        int numMid2 = nums2[mid2];

        int mid1In2 = std::distance(
            nums2.begin(),
            std::lower_bound(nums2.begin(), nums2.end(), numMid1));
        int mid2In1 = std::distance(
            nums1.begin(),
            std::lower_bound(nums1.begin(), nums1.end(), numMid2));
        int mid1InMerged = mid1 + mid1In2;
        int mid2InMerged = mid2 + mid2In1;

        if (mid2In1 == 0 && mid1In2 == 0) {
            return numMid1;
        }

        if (mid1InMerged == (m + n) / 2) {
            // std::cout << "mid1: " << mid1 << " = " << numMid1 << "\n";
            // std::cout << "mid1In2: " << mid1In2 << "\n";
            if ((m + n) % 2 == 0) {
                int k1 = mid1 - 1, k2 = mid1In2 - 1;
                k1 = k1 >= 0 ? nums1[k1] : IntMin;
                k2 = k2 >= 0 ? nums2[k2] : IntMin;
                return double(std::max(k1, k2) + numMid1) / 2;
            } else {
                return numMid1;
            }
        }
        if (mid2InMerged == (m + n) / 2) {
            // std::cout << "mid2: " << mid2 << " = " << numMid2 << "\n";
            // std::cout << "mid2In1: " << mid2In1 << "\n";

            if ((m + n) % 2 == 0) {
                int k2 = mid2 - 1, k1 = mid2In1 - 1;
                k1 = k1 >= 0 ? nums1[k1] : IntMin;
                k2 = k2 >= 0 ? nums2[k2] : IntMin;
                return double(std::max(k1, k2) + numMid2) / 2;
            } else {
                return numMid2;
            }
        }

        if (numMid2 > numMid1) {
            l1 = mid1;
            r2 = mid2;
        } else {
            l2 = mid2;
            r1 = mid1;
        }
    } while (true);
}