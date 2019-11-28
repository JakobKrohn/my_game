project(components)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

add_subdirectory(movable)
add_subdirectory(player)

target_link_libraries(${PROJECT_NAME}
    INTERFACE
        player::player
        movable::movable
)