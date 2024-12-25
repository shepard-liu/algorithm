#include "ackermann_function.hpp"

#include <iostream>
#include <tuple>
#include <vector>

#include "gtest/gtest.h"

TEST(misc, ackermann_function) {
    const std::vector<std::tuple<unsigned long, unsigned long, unsigned long>>
        cases{{1, 0, 0}, {0, 1, 0}, {1, 1, 0}, {2, 2, 0},
              {3, 4, 0}, {2, 3, 0}, {3, 3, 0}};

    // for (auto [m, n, expected] : cases) {
    //     unsigned long ans = ackermann_function_stack(m, n);
    //     std::cout << "A(" << m << ", " << n << ") = " << ans << std::endl;
    // }

    unsigned long ans = ackermann_function_stack(3, 4);
    std::cout << "A(" << 3 << ", " << 4 << ") = " << ans << std::endl;
}