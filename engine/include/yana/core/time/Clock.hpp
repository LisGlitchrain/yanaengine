#include <chrono>

namespace yana::core::time {
using Clock = std::chrono::steady_clock;

using TimePoint = Clock::time_point;

using Duration = Clock::duration;

using Seconds = std::chrono::duration<double>;
} // namespace yana::core::time