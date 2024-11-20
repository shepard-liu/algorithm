#include "modular_exponentiation.hpp"

uint64_t modular_exponentiation(uint64_t b, uint64_t n, uint64_t m) {
    uint64_t p = b % m;
    uint64_t ans = 1;

    while (n != 0) {
        uint64_t a = n & 1;
        n >>= 1;
        if (a == 1) {
            ans = (ans * p) % m;
        }
        p = (p * p) % m;
    };

    return ans;
}