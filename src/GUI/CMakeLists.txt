cmake_minimum_required(VERSION 3.14)

set(TARGET_NAME GUI)

file(GLOB SOURCES_C "*.c")
file(GLOB SOURCES_CPP "*.cpp")
file(GLOB HEADERS_H "*.h")
file(GLOB HEADERS_HPP "*.hpp")

set(HEADERS ${HEADERS_H} ${HEADERS_HPP})
set(SOURCES ${SOURCES_C} ${SOURCES_CPP})

add_library(${TARGET_NAME} STATIC ${SOURCES} ${HEADERS})
target_compile_options(${TARGET_NAME} PRIVATE -std=c++17 -Wall -Wextra -Wpedantic)


# Fetch SFML on Windows
IF (WIN32)
  message(STATUS "Fetching SFML...")

  # SFML flags
  set(SFML_STATIC_LIBRARIES TRUE)
  set(SFML_BUILD_AUDIO FALSE)
  set(SFML_BUILD_NETWORK FALSE)

  # Fetch from github
  FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML"
    GIT_TAG 2f11710abc5aa478503a7ff3f9e654bd2078ebab # v2.5.1
  )

  FetchContent_MakeAvailable(sfml)
ENDIF()

message("Linking ${TARGET_NAME}...")

if (WIN32)
  target_link_libraries(${TARGET_NAME} PUBLIC sfml-main sfml-system sfml-window sfml-graphics)
ELSEIF (UNIX)
  target_link_libraries(${TARGET_NAME} PUBLIC sfml-system sfml-window sfml-graphics)
ENDIF()
