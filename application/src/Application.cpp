#include <yana/application/Application.hpp>
#include <yana/engine/Engine.hpp>

namespace yana::application {
Application::Application() : engine_(std::make_unique<yana::engine::Engine>()) {}

Application::~Application() = default;

int Application::Run() {
    engine_->Initialize();
    engine_->Shutdown();
    return 0;
}
} // namespace yana::application
