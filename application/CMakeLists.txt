project(application)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        game::game
        sdl_input_event::sdl_input_event
)
