cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(my_game)

set(LIBRARY_NAME ${PROJECT_NAME})
message("my_game: ${LIBRARY_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Wnull-dereference")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON")

######### TEST #########
include(CTest)

add_subdirectory(external)
add_subdirectory(libraries)
add_subdirectory(src)
#add_subdirectory(test)
add_subdirectory(application)
