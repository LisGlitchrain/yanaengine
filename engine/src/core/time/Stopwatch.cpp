#include <yana/core/time/Stopwatch.hpp>

#include <chrono>

namespace yana::core::time {

Stopwatch::Stopwatch() : m_StartTime(Clock::now()) {}

void Stopwatch::Reset() { m_StartTime = Clock::now(); }

Duration Stopwatch::Elapsed() const { return Clock::now() - m_StartTime; }

double Stopwatch::ElapsedSeconds() const {
    return std::chrono::duration<double>(Elapsed()).count();
}

double Stopwatch::ElapsedMilliseconds() const {
    return std::chrono::duration<double, std::milli>(Elapsed()).count();
}

} // namespace yana::core::time