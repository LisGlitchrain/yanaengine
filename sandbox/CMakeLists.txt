add_executable(yana_sandbox
    src/main.cpp
)

target_link_libraries(yana_sandbox
    PRIVATE
        yana_application
)

yana_enable_warnings(yana_sandbox)
yana_enable_sanitizers(yana_sandbox)
