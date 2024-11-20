

#include <cstdint>

/**
 * @brief A trivial method to find the base r discrete logarithm of a modular p
 *
 * If not exist, 0 is returned.
 *
 * @param a
 * @param r
 * @param p
 * @return uint64_t
 */
uint64_t discrete_logarithm(uint64_t a, uint64_t r, uint64_t p);