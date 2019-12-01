project(external)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

add_subdirectory(sdl2)

target_link_libraries(${PROJECT_NAME} INTERFACE 
    PRIVATE
        #
)
