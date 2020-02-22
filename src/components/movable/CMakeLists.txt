project(movable)

message("${LIBRARY_NAME} --> ${PROJECT_NAME}")

add_library(${PROJECT_NAME} SHARED)
add_library(${LIBRARY_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        logger::logger
        ${LIBRARY_NAME}::sprite
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/Movable.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# add_executable(tests test/MovableTest.cpp)
# include(GoogleTest)
# target_link_libraries(tests gtest_main)
# target_link_libraries(tests test::test)
# gtest_discover_tests(tests)