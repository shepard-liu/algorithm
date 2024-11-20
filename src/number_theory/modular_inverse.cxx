
#include "modular_inverse.hpp"

#include "bezout_coeffs.hpp"

int64_t modular_inverse(int64_t a, int64_t m) {
    int b = bezout_coeffs(a, m).first;
    if ((b * a - 1) % m != 0) {
        return 0;
    }
    return b;
}