project(game)

# Interface library don't need sources
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

add_subdirectory(components)
add_subdirectory(game_engine)
add_subdirectory(graphic)
add_subdirectory(input_event)

target_link_libraries(${PROJECT_NAME} 
    INTERFACE 
        components::components
        game_engine::game_engine
        input_event::input_event
)
