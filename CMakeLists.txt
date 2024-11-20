cmake_minimum_required(VERSION 3.18)

project(algorithms)

include(cmake/executables.cmake)
include(cmake/tests.cmake)

find_package(GTest REQUIRED QUIET)
enable_testing()

add_subdirectory(src)