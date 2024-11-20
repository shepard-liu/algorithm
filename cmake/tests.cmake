macro(cxx_test name sources)
  message(STATUS "Adding test: ${name} (${sources}) with ${ARGN}")
  add_executable(${name} ${sources})
  target_link_libraries(${name} GTest::gtest_main ${ARGN})
  gtest_discover_tests(${name} WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  set_target_properties(
    ${name}
    PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED YES
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests"
  )

endmacro()
