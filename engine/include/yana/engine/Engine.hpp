#pragma once

namespace yana::engine
{
class Engine final
{
public:
    Engine();
    ~Engine();

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    void Initialize();
    void Shutdown();
};
} // namespace yana::engine
