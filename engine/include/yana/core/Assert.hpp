// engine/include/yana/core/Assert.hpp
#pragma once

#include <source_location>
#include <string_view>

namespace yana::core {
[[noreturn]] void
AssertFail(std::string_view expression, std::string_view message,
           const std::source_location &location = std::source_location::current());
}

#define YANA_ASSERT(expr)                                                                          \
    do {                                                                                           \
        if (!(expr)) {                                                                             \
            ::yana::core::AssertFail(#expr, {}, std::source_location::current());                  \
        }                                                                                          \
    } while (false)

#define YANA_ASSERT_MSG(expr, msg)                                                                 \
    do {                                                                                           \
        if (!(expr)) {                                                                             \
            ::yana::core::AssertFail(#expr, (msg), std::source_location::current());               \
        }                                                                                          \
    } while (false)