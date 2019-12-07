project(application)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    game::game
    # sdl_implementation::sdl_implementation
    sdl_input_event::sdl_input_event
)
