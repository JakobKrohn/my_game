project(sdl_implementation)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} 
        ${PROJECT_SOURCE_DIR}/sdl2-cmake-scripts
)

# set(SDL2_BUILDING_LIBRARY true)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

if (${SDL2_FOUND})
    message(STATUS "SDL lib found!")
else()  
    message(FATAL "SDL NOT found")
endif()

message(STATUS "SDL_LIB: ${SDL2_LIBRARY}")
message(STATUS "SDL_IMG_LIB: ${SDL2_IMAGE_LIBRARIES}")

target_link_libraries(${PROJECT_NAME}
    INTERFACE
        ${SDL2_LIBRARY} 
        ${SDL2_IMAGE_LIBRARIES} 
)

target_sources(${PROJECT_NAME}
    INTERFACE
        #
)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
)

# add_subdirectory(sdl_input_event)


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
