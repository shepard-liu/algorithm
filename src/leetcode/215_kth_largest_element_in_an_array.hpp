// https://leetcode.cn/problems/kth-largest-element-in-an-array/ Kth Largest
// Element in an Array
#include <asm-generic/errno.h>

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <queue>
#include <string>
#include <type_traits>
#include <vector>

#include "../test_utils.hpp"
using namespace std;

inline void shiftDown(vector<int>& data, int p, int n) {
    while (true) {
        int lc = p * 2 + 1;
        int rc = p * 2 + 2;
        if (rc >= n) {
            rc = lc;
        }
        if (lc >= n) {
            break;
        }
        if (data[p] >= data[lc] && data[p] >= data[rc]) {
            break;
        }
        if (data[lc] > data[rc]) {
            std::swap(data[p], data[lc]);
            p = lc;
        } else {
            std::swap(data[p], data[rc]);
            p = rc;
        }
    };
}

inline void shiftUp(vector<int>& data, int i) {
    if (i == 0) {
        return;
    }
    while (true) {
        int p = (i - 1) / 2;
        if (data[p] < data[i]) {
            std::swap(data[p], data[i]);
            i = p;
        } else {
            break;
        }
        if (i == 0) {
            break;
        }
    }
}

inline void makeHeap(vector<int>& data) {
    int n = data.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        shiftDown(data, i, n);
    }
}

inline void heapSort(vector<int>& heap) {
    for (int i = heap.size() - 1; i >= 0; --i) {
        std::swap(heap[0], heap[i]);
        shiftDown(heap, 0, i);
    }
}

inline int findKthLargest(vector<int>& nums, int k) {
    makeHeap(nums);
    // visualize_tree("data/heap_bin_tree.dot", nums);
    int end = nums.size();
    for (int i = 0; i < k; ++i) {
        std::swap(nums[0], nums[end]);
        shiftDown(nums, 0, end--);
    }
    return nums[nums.size() - k];
}