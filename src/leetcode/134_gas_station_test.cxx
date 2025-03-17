#include "134_gas_station.hpp"

#include <gtest/gtest.h>

#include <cstddef>
#include <vector>

#include "../test_utils.hpp"

typedef std::pair<std::vector<int>, std::vector<int>> TestCase;

void test_gas_station(TestCase& c) {
    auto& [gas, cost] = c;
    size_t n = gas.size();

    int startIndex = -1;
    for (size_t i = 0; i < n; ++i) {
        int accum = 0;
        for (size_t j = i; j < i + n; ++j) {
            size_t idx = j % n;
            accum += gas[idx] - cost[idx];
            if (accum < 0) {
                break;
            }
        }
        if (accum >= 0) {
            startIndex = i;
            break;
        }
    }
    std::cout << "gas:" << gas << "\ncost:" << cost << std::endl;
    EXPECT_EQ(startIndex, canCompleteCircuit(gas, cost));
}

TEST(leetcode, gas_station) {
    std::vector<TestCase> cases{{{1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}},
                                {{2, 3, 4}, {3, 4, 3}},
                                {{5, 8, 2, 8}, {6, 5, 6, 6}}};

    for (TestCase& c : cases) {
        test_gas_station(c);
    }
}
