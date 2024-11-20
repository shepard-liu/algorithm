#include "prng.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

#include "modular_exponentiation.hpp"

std::vector<uint64_t> linear_congruential_generator(uint64_t m, uint64_t a,
                                                    uint64_t c, uint64_t x0) {
    x0 = x0 % m;
    std::vector<uint64_t> psrns{x0};

    psrns.reserve(m);

    uint64_t x = x0;
    while (true) {
        x = (a * x + c) % m;
        if (x != x0) {
            psrns.push_back(x);
        } else {
            break;
        }
    }

    return psrns;
}

std::vector<uint64_t> power_congruential_generator(uint64_t p, uint64_t d,
                                                   uint64_t x0) {
    x0 = x0 % p;
    std::vector<uint64_t> psrns{x0};

    psrns.reserve(p);

    uint64_t x = x0;

    while (true) {
        x = modular_exponentiation(x, d, p);
        if (x != x0 && x != 1) {
            psrns.push_back(x);
        } else {
            break;
        }
    }

    return psrns;
}