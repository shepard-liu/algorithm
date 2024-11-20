#include "bezout_coeffs.hpp"

#include <cmath>
#include <cstdio>
#include <iostream>
#include <type_traits>

std::pair<int64_t, int64_t> bezout_coeffs(int64_t m, int64_t n) {
    int64_t signM = m < 0 ? -1 : 1, signN = n < 0 ? -1 : 1;
    m = signM * m;
    n = signN * n;
    bool swap = m < n;
    if (swap) {
        std::swap(m, n);
    }

    int64_t s1 = 1, s2 = 0, t1 = 0, t2 = 1;
    while (n != 0) {
        int64_t q = m / n;
        int64_t r = m - n * q;
        m = n;
        n = r;

        int64_t t = s1 - s2 * q;
        s1 = s2;
        s2 = t;
        t = t1 - t2 * q;
        t1 = t2;
        t2 = t;
    }

    if (swap) {
        std::swap(s1, t1);
    }

    return {s1 * signM, t1 * signN};
}