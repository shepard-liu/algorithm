
add_subdirectory(sorting)
add_subdirectory(strings)
add_subdirectory(number_theory)
add_subdirectory(misc)
add_subdirectory(searching)
add_subdirectory(combinatorics)
add_subdirectory(leetcode)

cxx_executable(main "")
target_sources(
    main PRIVATE main.cxx
)