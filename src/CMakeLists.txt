cmake_minimum_required(VERSION 3.14)

add_compile_options(-std=c++17)

add_subdirectory(Circuit)
add_subdirectory(Solver)
add_subdirectory(GUI)

file(GLOB SOURCES_MAIN "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES_MAIN})
target_compile_options(${PROJECT_NAME} PRIVATE -std=c++17 -Wall -Wextra -Wpedantic -g)
target_link_libraries(${PROJECT_NAME} GUI)
target_link_libraries(${PROJECT_NAME} Solver)
target_link_libraries(${PROJECT_NAME} Circuit)

