add_library(${PROJECT_NAME}_modules SHARED)

target_include_directories(${PROJECT_NAME}_modules
    PUBLIC
        ${GLOBAL}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(movable)