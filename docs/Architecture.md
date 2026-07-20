# Engine Architecture

## Vision

This project is an educational game engine written in modern C++.

Its primary goals are:

- Learn modern C++
- Learn Vulkan
- Learn graphics programming
- Learn engine architecture
- Build a cross-platform editor
- Produce reusable libraries where possible

The project is not intended to compete with commercial engines.

---

## Design Principles

- Simplicity before optimization.
- Modular architecture.
- Clear ownership of responsibilities.
- Cross-platform by design.
- Engine code must not depend on editor code.
- Prefer composition over inheritance.
- Prefer explicit interfaces over hidden behavior.

---

## High-Level Architecture

(To be filled as the engine evolves.)
```text
Engine
│
├── Core
├── Platform
├── Renderer
├── Scene
├── Assets
└── Runtime
```
---

## Design Decisions

This section records important architectural decisions together with the reasoning behind them.

### ADR-0001

Reserved.