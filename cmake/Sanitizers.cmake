option(YANA_ENABLE_ASAN
    "Enable AddressSanitizer"
    OFF
)

option(YANA_ENABLE_UBSAN
    "Enable UndefinedBehaviorSanitizer"
    OFF
)

function(yana_enable_sanitizers target)

    if(NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        return()
    endif()

    if(YANA_ENABLE_ASAN)

        target_compile_options(${target}
            PRIVATE
                -fsanitize=address
        )

        target_link_options(${target}
            PRIVATE
                -fsanitize=address
        )

    endif()

    if(YANA_ENABLE_UBSAN)

        target_compile_options(${target}
            PRIVATE
                -fsanitize=undefined
        )

        target_link_options(${target}
            PRIVATE
                -fsanitize=undefined
        )

    endif()

endfunction()