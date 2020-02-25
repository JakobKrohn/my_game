project(game_engine)

add_library(${PROJECT_NAME} SHARED)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        graphics_interface::graphics_interface
        input_event_interface::input_event_interface
        components::components
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/GameEngine.cpp
        ${PROJECT_SOURCE_DIR}/src/Factory.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    PRIVATE
        $<INSTALL_INTERFACE:include/internal>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/internal>
)

get_property(TEST_SOURCES GLOBAL PROPERTY source_list_property)
SET(ENGINE_TESTS
    ${TEST_SOURCES}
    "${CMAKE_CURRENT_SOURCE_DIR}/test/GameEngineTest.cpp"
)
set_property(GLOBAL PROPERTY source_list_property "${ENGINE_TESTS}")