project(sdl_lib)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} 
        ${PROJECT_SOURCE_DIR}/sdl2-cmake-scripts
)

add_subdirectory(install_sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

if (${SDL2_FOUND})
    message(STATUS "SDL IS INSTALLED AND FOUND!")
else()  
    message(FATA_ERROR "SDL COULD NOT BE INSTALLED/FOUND")
    # message(FATAL_ERROR "SDL2 not found. ")
    # message(STATUS "SDL is not found, trying install")
    
    # find_package(SDL2 REQUIRED)
    # find_package(SDL2_image REQUIRED)

    # if (${SDL2_FOUND})
    #     message(STATUS "SDL IS INSTALLED AND FOUND!")
    # else()  
    #     message(FATA_ERROR "SDL COULD NOT BE INSTALLED/FOUND")
    # endif()
endif()

message(STATUS "SDL_LIB: ${SDL2_LIBRARY}")
message(STATUS "SDL_IMG_LIB: ${SDL2_IMAGE_LIBRARIES}")

target_link_libraries(${PROJECT_NAME}
    INTERFACE
        ${SDL2_LIBRARY} 
        ${SDL2_IMAGE_LIBRARIES} 
)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
)

