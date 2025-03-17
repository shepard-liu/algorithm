// https://leetcode.cn/problems/gas-station/ Gas Station
#include <cstddef>
#include <limits>
#include <vector>
using namespace std;

inline int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    size_t n = gas.size();
    int deltaSum = 0, minDeltaSum = std::numeric_limits<int>::max();
    int minDeltaSumIndex = -1;
    for (size_t i = 0; i < n; ++i) {
        int delta = gas[i] - cost[i];
        deltaSum += delta;
        if (deltaSum < minDeltaSum) {
            minDeltaSum = deltaSum;
            minDeltaSumIndex = i;
        }
    }

    if (deltaSum < 0) {
        return -1;
    }

    return (minDeltaSumIndex + 1) % n;
}