cmake_minimum_required(VERSION 3.14)

set(SOURCES 
  netlist_tests.cpp
  circuit_load_tests.cpp
  circuit_test.cpp
)

add_executable(UnitTests ${SOURCES})
target_compile_options(UnitTests PRIVATE -std=c++17 -Wall -Wextra -Wpedantic)

message("Linking unit tests...")
target_link_libraries(UnitTests PUBLIC
  gtest_main
  Circuit
  Solver
  GUI
)

add_test(
  NAME UnitTests
  COMMAND UnitTests
)
