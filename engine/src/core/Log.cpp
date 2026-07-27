// Inside the intermediate header
#include <iostream>
#include <string> // IWYU pragma: keep
#include <yana/core/Log.hpp>

namespace yana::core {
std::string ToString(LogLevel _Level) {
    switch (_Level) {
    case LogLevel::Trace:
        return "Trace";
    case LogLevel::Debug:
        return "Debug";
    case LogLevel::Info:
        return "Info";
    case LogLevel::Warning:
        return "Warning";
    case LogLevel::Error:
        return "Error";
    case LogLevel::Fatal:
        return "Fatal";
    }
}

void Log(LogLevel level, std::string_view message) {
    std::cout << '[' << ToString(level) << "] " << message << '\n';
}
} // namespace yana::core