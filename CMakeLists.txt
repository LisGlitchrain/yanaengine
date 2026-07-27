cmake_minimum_required(VERSION 3.28)

project(
    YanaEngine
    VERSION 0.0.1
    LANGUAGES CXX
)

include(cmake/ProjectOptions.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/StaticAnalyzers.cmake)
include(cmake/Sanitizers.cmake)
include(cmake/CCache.cmake)

yana_setup_project_options()

include(CTest)
add_subdirectory(engine)
add_subdirectory(application)
add_subdirectory(sandbox)

get_target_property(ENGINE_INCLUDE_DIRS yana_engine INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "yana_engine INTERFACE_INCLUDE_DIRECTORIES = ${ENGINE_INCLUDE_DIRS}")

get_target_property(APP_LINK_LIBS yana_application LINK_LIBRARIES)
message(STATUS "yana_application LINK_LIBRARIES = ${APP_LINK_LIBS}")