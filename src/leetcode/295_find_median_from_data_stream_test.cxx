#include "295_find_median_from_data_stream.hpp"

#include <iostream>
#include <map>
#include <vector>

#include "../test_utils.hpp"
typedef int TestCase;

std::set<int> arr;

void addNum(MedianFinder& finder, int num) {
    std::cout << "AddNum: " << num << std::endl;
    arr.insert(num);
    finder.addNum(num);
}

void findMedian(MedianFinder& finder) {
    std::cout << "FindMedian: " << finder.findMedian() << "\n";
    std::cout << "Current array: ";
    for (auto n : arr) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
}

TEST(leetcode, find_median_from_data_stream) {
    MedianFinder finder;
    std::vector<int> arr{1, 2, 3, 8, 6, 9, 2, 6, 8};
    for (auto n : arr) {
        addNum(finder, n);
        findMedian(finder);
    }
}
