add_library(${PROJECT_NAME}_sdl_specific SHARED) 

# Add scripts for finding SDL
set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} 
        "${PROJECT_SOURCE_DIR}/external/sdl2-cmake-scripts"
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(${PROJECT_NAME}_sdl_specific 
    PUBLIC
        ${SDL2_LIBRARIES} 
        ${SDL2_IMAGE_LIBRARIES} 
)

target_include_directories(${PROJECT_NAME}_sdl_specific
    PUBLIC
        ${GLOBAL}
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
)

add_subdirectory(Graphic)
add_subdirectory(Input)
