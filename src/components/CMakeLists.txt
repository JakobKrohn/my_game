project(components)

set(LIBRARY_NAME ${PROJECT_NAME})
message("${LIBRARY_NAME} --> ${PROJECT_NAME}")

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

add_subdirectory(drawable)
add_subdirectory(movable)
add_subdirectory(player)
add_subdirectory(sprite)

target_link_libraries(${PROJECT_NAME}
    INTERFACE
        ${LIBRARY_NAME}::drawable
        ${LIBRARY_NAME}::player
        ${LIBRARY_NAME}::movable
        ${LIBRARY_NAME}::sprite
)
