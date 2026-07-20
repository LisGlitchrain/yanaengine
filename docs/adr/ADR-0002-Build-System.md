# ADR-0002 — Build System

**Status:** Accepted

**Date:** 2026-07-20

---

## Context

The project targets Linux as the primary development platform while supporting Windows and macOS.

The build system should:

* support multiple compilers;
* integrate well with modern IDEs;
* encourage modular libraries;
* be widely adopted by the C++ ecosystem;
* simplify dependency management;
* remain maintainable for many years.

Several options were considered, including CMake and SCons.

---

## Decision

The project will use **CMake** as its build system.

Additional decisions:

* Minimum CMake version will be chosen according to current stable tooling.
* Ninja will be the preferred generator.
* The project will target C++23.
* Build descriptions will follow modern target-based CMake practices.
* Each engine module will become an independent CMake target.

Example:

```cmake
add_library(Core)

add_library(Renderer)

target_link_libraries(Renderer PUBLIC Core)
```

Applications such as Editor, Sandbox, and Game will link against these targets rather than compiling engine sources directly.

---

## Rationale

CMake was selected because it:

* is the de facto standard for modern C++ projects;
* integrates well with VS Code, CLion, Visual Studio, and Xcode;
* is supported by nearly every graphics-related library;
* works naturally with package managers such as vcpkg and Conan;
* encourages explicit dependency management through targets;
* supports all intended target platforms.

---

## Consequences

### Advantages

* Excellent ecosystem support.
* Large amount of documentation.
* Cross-platform project generation.
* Modern IDE integration.
* Easy dependency management.
* Clean modular architecture.

### Disadvantages

* CMake language has a learning curve.
* Older tutorials often demonstrate obsolete practices.

These disadvantages are outweighed by ecosystem support and long-term maintainability.

---

## Alternatives Considered

### SCons

Advantages:

* Python-based.
* Very flexible.
* Easy to extend.

Rejected because:

* significantly smaller ecosystem;
* weaker IDE integration;
* most third-party graphics libraries already provide CMake support.

Python remains an excellent choice for future development tools such as shader compilation, asset processing, and packaging.

---

## Future Considerations

The project will initially use static libraries for engine modules.

Runtime plugin loading may be introduced later if justified by project requirements.

The build system should evolve without requiring major architectural changes.
