add_library(${PROJECT_NAME} 
    SHARED 
        BoxHead.cpp
)

set(GLOBAL "${PROJECT_SOURCE_DIR}/src/global")

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(sdl_specific)
add_subdirectory(modules)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_NAME}_sdl_specific
        ${PROJECT_NAME}_modules
)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})