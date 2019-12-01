project(sdl_implementation)

# add_library(${PROJECT_NAME} SHARED)
# add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} 
        ${PROJECT_SOURCE_DIR}/sdl2-cmake-scripts
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(sdl_input_event)


# target_link_libraries(${PROJECT_NAME}
#     PRIVATE
#         #
# )

# target_sources(${PROJECT_NAME}
#     PRIVATE
#         #
# )

# target_include_directories(${PROJECT_NAME}
#     PUBLIC
#         ${PROJECT_SOURCE_DIR}/include
# )
