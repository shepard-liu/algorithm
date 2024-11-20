#include "gcd.hpp"

#include <cmath>
#include <tuple>

int64_t gcd(int64_t m, int64_t n) {
    m = std::abs(m);
    n = std::abs(n);

    if (m < n) {
        std::swap(m, n);
    }

    while (n != 0) {
        int64_t r = m % n;
        m = n;
        n = r;
    }

    return m;
}