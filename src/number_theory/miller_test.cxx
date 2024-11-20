#include "miller_test.hpp"

#include <cmath>
#include <iostream>

#include "modular_exponentiation.hpp"

bool miller_test(uint64_t n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    // find s and t
    uint64_t t = n - 1, s = 0;

    while (t % 2 == 0) {
        t /= 2;
        s++;
    }

    for (uint64_t b = 2; b < n; ++b) {
        uint64_t bpt = modular_exponentiation(b, t, n);

        if (bpt == 1 || bpt == n - 1) {
            continue;
        }

        uint64_t j = 1;
        for (; j < s; ++j) {
            bpt = (bpt * bpt) % n;
            if (bpt % n == n - 1) {
                break;
            }
        }

        if (j == s) {
            return false;
        }
    }

    return true;
}