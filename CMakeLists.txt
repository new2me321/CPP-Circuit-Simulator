cmake_minimum_required(VERSION 3.14)
add_compile_options(-std=c++17)
project(circuit-simulator)

add_definitions(-DRESOURCES_PATH="${RESOURCES_PATH}")
add_definitions(-DSAVEFILES_PATH="${SAVEFILES_PATH}")

add_subdirectory(libs)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
