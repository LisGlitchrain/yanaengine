add_executable(Sandbox
    main.cpp
)

target_link_libraries(Sandbox
)

yana_enable_warnings(Sandbox)
yana_enable_sanitizers(Sandbox)