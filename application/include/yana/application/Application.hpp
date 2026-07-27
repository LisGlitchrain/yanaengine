#pragma once

#include <memory>

namespace yana::engine
{
class Engine;
}

namespace yana::application
{
class Application final
{
public:
    Application();
    ~Application();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    int Run();

private:
    std::unique_ptr<yana::engine::Engine> engine_;
};
} // namespace yana::application
