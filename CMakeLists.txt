cmake_minimum_required(VERSION 3.18)

project(algorithms)

set (CMAKE_CXX_FLAGS "-fstandalone-debug")
include(cmake/executables.cmake)
include(cmake/tests.cmake)

# iterators, ranges
find_package(Boost REQUIRED)

find_package(GTest REQUIRED QUIET)
enable_testing()

add_subdirectory(src)