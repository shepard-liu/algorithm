

#include <cstdint>
#include <vector>

std::vector<uint64_t> linear_congruential_generator(uint64_t m, uint64_t a,
                                                    uint64_t c, uint64_t x0);

/**
 * @brief
 *
 * @param p a prime.
 * @param d should not be divisible by p
 * @return std::vector<uint64_t>
 */
std::vector<uint64_t> power_congruential_generator(uint64_t p, uint64_t d,
                                                   uint64_t x0);