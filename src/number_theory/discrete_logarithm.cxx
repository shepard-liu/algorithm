#include "discrete_logarithm.hpp"

uint64_t discrete_logarithm(uint64_t a, uint64_t r, uint64_t p) {
    uint64_t log = 1;
    uint64_t exp = r;
    while (exp != a && log < p) {
        exp = (exp * r) % p;
        log++;
    }
    if (log == p) {
        return 0;
    }
    return log;
}