cmake_minimum_required(VERSION 3.14)

set(TARGET_NAME Circuit)

file(GLOB SOURCES_C "*.c")
file(GLOB SOURCES_CPP "*.cpp")
file(GLOB HEADERS_H "*.h")
file(GLOB HEADERS_HPP "*.hpp")

set(HEADERS ${HEADERS_H} ${HEADERS_HPP})
set(SOURCES ${SOURCES_C} ${SOURCES_CPP})

message("Linking ${TARGET_NAME}...")
add_library(${TARGET_NAME} STATIC ${SOURCES} ${HEADERS})
target_compile_options(${TARGET_NAME} PRIVATE -std=c++17 -Wall -Wextra -Wpedantic -g)
target_include_directories(${TARGET_NAME} PRIVATE "..")
