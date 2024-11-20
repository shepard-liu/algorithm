
add_subdirectory(sorting)
add_subdirectory(strings)
add_subdirectory(number_theory)
add_subdirectory(misc)

cxx_executable(main "")
target_sources(
    main PRIVATE main.cxx
)