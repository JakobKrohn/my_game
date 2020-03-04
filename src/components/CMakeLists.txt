project(components)

set(LIBRARY_NAME ${PROJECT_NAME})
message("${LIBRARY_NAME} --> ${PROJECT_NAME}")

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

add_subdirectory(movable)
add_subdirectory(player)

target_link_libraries(${PROJECT_NAME}
    INTERFACE
        ${LIBRARY_NAME}::player
        ${LIBRARY_NAME}::movable
)

get_property(TEST_SOURCES GLOBAL PROPERTY source_list_property)
SET(COMPONENTS_TESTS
    ${TEST_SOURCES}
    "${CMAKE_CURRENT_SOURCE_DIR}/player/test/PlayerTest.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/movable/test/MovableTest.cpp"
)
set_property(GLOBAL PROPERTY source_list_property "${COMPONENTS_TESTS}")