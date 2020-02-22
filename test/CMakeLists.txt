project(testing)

# https://github.com/google/googletest/tree/master/googletest
# ==============================================================================
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()
# ==============================================================================

include(GoogleTest)
# enable_testing()

# add_library(${PROJECT_NAME} UNKNOWN IMPORTED GLOBAL)
# add_library(${LIBRARY_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# add_dependencies(${PROJECT_NAME} googletest)

# set_property(TARGET luajit PROPERTY IMPORTED_LOCATION ${install_dir}/lib/libluajit-5.1.a)

# target_link_libraries(${PROJECT_NAME} INTERFACE gtest_main)
# target_sources(${PROJECT_NAME} INTERFACE main.cpp)

# gtest_discover_tests(${PROJECT_NAME})

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example main.cpp ../src/components/movable/test/MovableTest.cpp)

target_link_libraries(example gtest_main)

gtest_discover_tests(example)


#-DGTEST_CREATE_SHARED_LIBRARY=1
# Compile gtest as shared lib: https://github.com/google/googletest/blob/master/googletest/README.md 
