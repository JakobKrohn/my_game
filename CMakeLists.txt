cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Wnull-dereference")
set(CMAKE_BUILD_TYPE Debug)

project(MY_GAME C CXX)

include(CTest)

add_subdirectory(external/doctest)
include(external/doctest/scripts/cmake/doctest.cmake)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(tools)
