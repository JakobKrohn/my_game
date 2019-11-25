add_executable(${PROJECT_NAME}Test
        doctest_main.cpp
        basic.cpp
)

# Give test target access to projects internal headers
set_property(TARGET ${PROJECT_NAME}Test PROPERTY ${PROJECT_NAME}_PRIVATE 1)

target_link_libraries(${PROJECT_NAME}Test
    PUBLIC
        ${PROJECT_NAME}
        # ${PROJECT_NAME}sdl_specific
        # ${PROJECT_NAME}_modules::${PROJECT_NAME}_modules
        doctest
)

# add_subdirectory(Player)
# add_subdirectory(Movable)

doctest_discover_tests(${PROJECT_NAME}Test)