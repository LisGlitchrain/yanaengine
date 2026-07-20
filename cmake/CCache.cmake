find_program(CCACHE_PROGRAM ccache)

if(CCACHE_PROGRAM)

    message(STATUS "Using ccache")

    set(CMAKE_CXX_COMPILER_LAUNCHER
        ${CCACHE_PROGRAM}
    )

endif()