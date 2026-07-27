function(yana_setup_project_options)
    set(CMAKE_CXX_STANDARD 23 PARENT_SCOPE)
    set(CMAKE_CXX_STANDARD_REQUIRED ON PARENT_SCOPE)
    set(CMAKE_CXX_EXTENSIONS OFF PARENT_SCOPE)

    set(CMAKE_EXPORT_COMPILE_COMMANDS ON PARENT_SCOPE)

    # We are not using C++ modules yet, and this avoids module-scanning flags
    # leaking into clang-tidy / compile commands.
    set(CMAKE_CXX_SCAN_FOR_MODULES OFF PARENT_SCOPE)
endfunction()