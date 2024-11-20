
#include <cstddef>
#include <ostream>
#include <vector>

#include "gtest/gtest.h"

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec);

/**
 * @brief Generator uniformly distributed random integers.
 *
 * @param size
 * @param seed default: 0
 * @param from default: 0
 * @param to default: 10
 * @return std::vector<int>
 */
std::vector<int> random_int_array(size_t size, size_t seed = 0, int from = 0,
                                  int to = 10);

typedef void (*Sort_func)(std::vector<int> &);

void test_sorting_algorithm(Sort_func func, std::size_t seed,
                            std::size_t size = 10);
