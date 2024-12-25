
#include "partitions_of_integer.hpp"

#include <iostream>

#include "gtest/gtest.h"

TEST(misc, partitions_of_integer) {
    EXPECT_EQ(partitions_of_integer(5), 7);
    EXPECT_EQ(partitions_of_integer(6), 11);

    for (unsigned long i = 1; i < 1000; ++i) {
        std::cout << "number of partitions of " << i << ": "
                  << partitions_of_integer(i) << std::endl;
    }
}