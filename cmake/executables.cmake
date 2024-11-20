# cxx_executable_with_flags(name cxx_flags libs srcs...)
#
# Creates a named C++ executable that depends on the given libraries and is
# built from the given source files.
macro(cxx_executable name libs)
  add_executable(${name})

  target_include_directories(${name} PRIVATE ${VERSIONING_GEN_DIR})

  target_link_libraries(${name} ${libs})

  list(APPEND EXE_TARGETS ${name})

  set_target_properties(
    ${name}
    PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED YES
      CXX_EXTENSIONS NO
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )
endmacro()
