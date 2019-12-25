project(drawable)

message("${LIBRARY_NAME} --> ${PROJECT_NAME}")

add_library(${PROJECT_NAME} SHARED)
add_library(${LIBRARY_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        logger::logger
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/Drawable.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
