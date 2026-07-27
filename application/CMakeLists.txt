add_library(yana_application STATIC
    src/Application.cpp
)

target_include_directories(yana_application
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(yana_application
    PUBLIC
        yana_engine
)

yana_enable_warnings(yana_application)
yana_enable_sanitizers(yana_application)
