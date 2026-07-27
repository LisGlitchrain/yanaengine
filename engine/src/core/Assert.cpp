#include <yana/core/Assert.hpp>

#include <cstdlib>
#include <iostream>

#if defined(_MSC_VER)
#include <intrin.h>
#endif

namespace yana::core {
[[noreturn]] void AssertFail(std::string_view expression, std::string_view message,
                             const std::source_location &location) {
    std::cerr << "Assertion failed: " << expression << '\n';

    if (!message.empty()) {
        std::cerr << "Message: " << message << '\n';
    }

    std::cerr << "Location: " << location.file_name() << ':' << location.line() << ':'
              << location.column() << '\n';

#if defined(_MSC_VER)
    __debugbreak();
#elif defined(__GNUC__) || defined(__clang__)
    __builtin_trap();
#endif

    std::abort();
}
} // namespace yana::core