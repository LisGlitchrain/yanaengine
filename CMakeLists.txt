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

add_subdirectory(sandbox)