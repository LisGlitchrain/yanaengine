function(yana_setup_static_analyzers)
    find_program(YANA_CLANG_TIDY_EXE NAMES clang-tidy)

    if(YANA_CLANG_TIDY_EXE)
        # Checks are controlled by .clang-tidy.
        set(CMAKE_CXX_CLANG_TIDY "${YANA_CLANG_TIDY_EXE}" PARENT_SCOPE)
    endif()
endfunction()