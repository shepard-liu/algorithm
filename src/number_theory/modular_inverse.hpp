
#include <cstdint>

/**
 * @brief Find such b that ba === 1 (mod m)
 *
 * If such b does not exist, 0 is returned.
 *
 * @param a
 * @param m
 * @return
 */
int64_t modular_inverse(int64_t a, int64_t m);