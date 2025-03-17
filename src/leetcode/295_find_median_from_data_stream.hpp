// https://leetcode.cn/problems/find-median-from-data-stream/ Find Median from
// Data Stream
#include <functional>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, std::greater<int>> right;

   public:
    MedianFinder() {}

    void addNum(int num) {
        int n = left.size() + right.size();
        if (n == 0) {
            left.push(num);
            return;
        }
        if (n % 2 == 0) {
            if (num <= right.top()) {
                left.push(num);
            } else {
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        } else {
            if (num <= left.top()) {
                right.push(left.top());
                left.pop();
                left.push(num);
            } else {
                right.push(num);
            }
        }
    }

    double findMedian() {
        int n = left.size() + right.size();
        if (n % 2 == 0) {
            return 0.5 * (left.top() + right.top());
        } else {
            return left.top();
        }
    }
};
