project(sdl_lib)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set(SDL2_INCLUDE_DIRS "/usr/include/SDL2")
set(SDL2_LIB "/usr/lib/x86_64-linux-gnu/libSDL2.so")

#set(SDL2_IMAGE_INCLUDE_DIRS "/usr/include/SDL2")
set(SDL2_IMAGE_LIB "/usr/lib/x86_64-linux-gnu/libSDL2_image.so")

#set(SDL2_TTF_IMAGE_INCLUDE_DIRS "/usr/include/SDL2")
set(SDL2_TTF_LIB "/usr/lib/x86_64-linux-gnu/libSDL2_ttf.so")

# if (${SDL2_FOUND})
#     message(STATUS "SDL IS INSTALLED AND FOUND!")
# else()  
#     message(FATAL_ERROR "SDL COULD NOT BE INSTALLED/FOUND")
# endif()

# message(STATUS "SDL_LIB: ${SDL2_LIBRARY}")
# message(STATUS "SDL_IMG_LIB: ${SDL2_IMAGE_LIBRARIES}")
# message(STATUS "SDL_TTF_LIB: ${SDL2_TTF_LIBRARIES}")

target_link_libraries(${PROJECT_NAME}
    INTERFACE
        ${SDL2_LIB} 
        ${SDL2_IMAGE_LIB} 
        ${SDL2_TTF_LIB}
)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
)
