project(game_engine)

set(LIBRARY_NAME ${PROJECT_NAME})
message("${LIBRARY_NAME} --> ${PROJECT_NAME}")

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    INTERFACE
        graphics_interface::graphics_interface
)

target_sources(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/src/GameEngine.cpp
        ${PROJECT_SOURCE_DIR}/src/Factory.cpp
)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
