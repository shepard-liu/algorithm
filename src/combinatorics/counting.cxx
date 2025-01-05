#include "counting.hpp"

#include <cmath>
#include <cstdint>

uint64_t factorial(uint64_t n) {
    uint64_t ans = 1;
    for (uint64_t i = 2; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

uint64_t binominal(uint64_t n, uint64_t r) {
    if (r >= std::ceil(n / 2)) {
        r = n - r;
    }

    uint64_t e = 1;
    for (uint64_t i = n - r + 1; i <= n; ++i) {
        e *= i;
    }

    return e / factorial(r);
}
