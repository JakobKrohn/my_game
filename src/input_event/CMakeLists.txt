project(input_event)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        #
)

target_sources(${PROJECT_NAME}
    PRIVATE
        # ${PROJECT_SOURCE_DIR}/src/InputEvent.cpp
)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)
