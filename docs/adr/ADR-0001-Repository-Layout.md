# ADR-0001 — Repository Layout

**Status:** Accepted

**Date:** 2026-07-20

---

## Context

The project is intended to be a long-term educational game engine written in modern C++. It should remain understandable as new systems are added, including rendering, assets, an editor, scripting, and tools.

A repository layout chosen early will influence build configuration, dependency management, documentation, and future modularization.

The structure should:

* separate engine code from applications;
* encourage modular development;
* support multiple executables (Editor, Game, Sandbox);
* allow reusable libraries;
* remain easy to navigate for a single developer.

---

## Decision

The repository will be organized as follows:

```text
Engine/
│
├── CMakeLists.txt
├── CMakePresets.json
├── README.md
├── .gitignore
├── .clang-format
├── .clang-tidy
│
├── docs/
├── cmake/
├── external/
│
├── Engine/
│
├── Editor/
├── Game/
├── Sandbox/
│
└── Tools/
```

### Responsibilities

**Engine/**

Contains all reusable engine libraries.

Examples:

* Core
* Platform
* Renderer
* Scene
* Assets
* Runtime

The engine must never depend on editor-specific code.

---

**Editor/**

Contains the editor host application.

It links against engine libraries and provides editor functionality such as:

* Hierarchy
* Inspector
* Viewport
* Asset Browser

---

**Game/**

Contains the runtime host used for running packaged games.

---

**Sandbox/**

Contains experimental applications used for learning and testing new engine features without affecting the editor or the game runtime.

---

**Tools/**

Contains standalone utilities such as:

* shader compiler
* asset pipeline
* packaging
* project generation

---

**external/**

Contains third-party dependencies that are part of the source tree or managed by CMake.

No project code should be written here.

---

**docs/**

Contains documentation and Architecture Decision Records.

Documentation is considered part of the project, not an afterthought.

---

## Consequences

### Advantages

* Clear separation of responsibilities.
* Engine remains independent from applications.
* Easy to create additional hosts.
* Supports reusable libraries.
* Documentation grows together with implementation.
* Easy navigation.

### Disadvantages

* Slightly more directories than a small project initially needs.
* Some folders remain empty during early development.

Both trade-offs are considered acceptable for a long-term project.

---

## Alternatives Considered

### Single `src/` directory

Rejected.

Although simple initially, it scales poorly as the project grows and encourages tight coupling.

---

### Monolithic Engine executable

Rejected.

Separating engine libraries from host applications allows the same engine to be used by the Editor, Game, Sandbox, and future tools.

---

### Separate repositories for engine and editor

Rejected.

Keeping everything in one repository simplifies development while the project is still evolving.
