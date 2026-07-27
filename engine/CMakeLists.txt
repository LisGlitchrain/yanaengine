add_library(yana_engine STATIC
    src/Engine.cpp
    src/core/Assert.cpp
    src/core/Log.cpp
    src/core/time/Stopwatch.cpp
)

target_include_directories(yana_engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

yana_enable_warnings(yana_engine)
yana_enable_sanitizers(yana_engine)
