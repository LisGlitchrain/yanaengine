#pragma once

#include <yana/core/time/Clock.hpp>

namespace yana::core::time {

class Stopwatch {
  public:
    Stopwatch();

    void Reset();

    [[nodiscard]]
    Duration Elapsed() const;

    [[nodiscard]]
    double ElapsedSeconds() const;

    [[nodiscard]]
    double ElapsedMilliseconds() const;

  private:
    TimePoint m_StartTime;
};

} // namespace yana::core::time