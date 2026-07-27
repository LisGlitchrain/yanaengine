// Inside the intermediate header
#include <format>
#include <string> // IWYU pragma: keep

namespace yana::core {
enum class LogLevel { Trace, Debug, Info, Warning, Error, Fatal };

template <typename... Args>
void LogFormatted(LogLevel level, std::format_string<Args...> format, Args &&...args) {
    Log(level, std::format(format, std::forward<Args>(args)...));
}
void Log(LogLevel level, std::string_view message);

#define YANA_LOG_TRACE(...) ::yana::core::LogFormatted(::yana::core::LogLevel::Trace, __VA_ARGS__)

#define YANA_LOG_DEBUG(...) ::yana::core::LogFormatted(::yana::core::LogLevel::Debug, __VA_ARGS__)

#define YANA_LOG_INFO(...) ::yana::core::LogFormatted(::yana::core::LogLevel::Info, __VA_ARGS__)

#define YANA_LOG_WARNING(...)                                                                      \
    ::yana::core::LogFormatted(::yana::core::LogLevel::Warning, __VA_ARGS__)

#define YANA_LOG_ERROR(...) ::yana::core::LogFormatted(::yana::core::LogLevel::Error, __VA_ARGS__)

#define YANA_LOG_FATAL(...) ::yana::core::LogFormatted(::yana::core::LogLevel::Fatal, __VA_ARGS__)
} // namespace yana::core
