#include <thread>
#include <yana/application/Application.hpp>
#include <yana/core/Assert.hpp>
#include <yana/core/Log.hpp>
#include <yana/core/time/Stopwatch.hpp>

using yana::core::Log;
using yana::core::LogLevel;
using yana::core::time::Stopwatch;

int main() {
    // example of assertion usage: YANA_ASSERT(1 + 1 == 3);
    yana::application::Application app;
    YANA_LOG_INFO("Yana Engine");
    Stopwatch sw;

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    YANA_LOG_INFO("Ellapsed: {}", sw.ElapsedMilliseconds());
    return app.Run();
}
