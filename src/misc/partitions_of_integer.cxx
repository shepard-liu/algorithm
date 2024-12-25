#include "partitions_of_integer.hpp"

/**
 * @brief number of partitions of m with all element less than n.
 *
 * @param m
 * @param n
 * @return unsigned long
 */
unsigned long partitions_of_integer_less_than_n(unsigned long m,
                                                unsigned long n) {
    if (m == 1) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
    if (m < n) {
        return partitions_of_integer_less_than_n(m, m);
    }
    if (m == n) {
        return 1 + partitions_of_integer_less_than_n(m, m - 1);
    }
    return partitions_of_integer_less_than_n(m, n - 1) +
           partitions_of_integer_less_than_n(m - n, n);
}

unsigned long partitions_of_integer(unsigned long m) {
    if (m == 0) {
        return 0;
    }
    return partitions_of_integer_less_than_n(m, m);
}