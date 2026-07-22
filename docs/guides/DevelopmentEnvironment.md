# Development Environment

## Purpose

This document describes the recommended development environment for **Yana Engine**.

The project aims to provide a consistent development experience across supported platforms while remaining easy to build for new contributors.

Although the engine targets Linux, Windows, and macOS, **Linux with Clang** is considered the primary development environment.

---

# Philosophy

The development environment should help developers detect problems as early as possible.

The preferred order of finding mistakes is:

```text
Compiler
    ↓
clang-tidy
    ↓
Sanitizers
    ↓
Debugger
```

Finding problems earlier makes them significantly cheaper to fix.

---

# Operating Systems

Primary development platform:

* Linux

Supported target platforms:

* Linux
* Windows
* macOS

The engine should remain portable and avoid unnecessary platform-specific code.

---

# Compiler

## Primary

Clang

Reasons:

* Excellent diagnostics
* First-class tooling
* Cross-platform
* Excellent C++ standards support
* Native integration with clangd, clang-format and clang-tidy

## Secondary

GCC

The project should continue to build successfully with GCC whenever practical.

---

# Build System

The project uses:

* CMake
* Ninja

CMake generates the build system.

Ninja performs the actual compilation.

---

# Required Tools

The recommended development environment consists of:

| Tool         | Purpose            |
| ------------ | ------------------ |
| CMake        | Project generation |
| Ninja        | Build backend      |
| Clang        | C++ compiler       |
| clangd       | Language server    |
| clang-format | Code formatting    |
| clang-tidy   | Static analysis    |
| Git          | Version control    |

---

# Optional Tools

These tools are not required but are recommended.

| Tool                        | Purpose                   |
| --------------------------- | ------------------------- |
| ccache                      | Faster incremental builds |
| LLDB                        | Debugging                 |
| RenderDoc                   | Graphics debugging        |
| Vulkan SDK                  | Vulkan development        |
| GPU vendor validation tools | Performance analysis      |

Additional tools may be added as the engine evolves.

---

# Editor

The recommended editor is:

Visual Studio Code

Recommended extensions include:

* CMake Tools
* C/C++
* clangd
* CodeLLDB
* EditorConfig
* GitLens
* GitHub Pull Requests

The repository contains a `.vscode/extensions.json` file with extension recommendations.

---

# Formatting

Source formatting is performed using:

* clang-format

The repository contains a project-wide `.clang-format` configuration.

Formatting should be automatic whenever possible.

---

# Static Analysis

Static analysis is performed using:

* clang-tidy

The project includes a `.clang-tidy` configuration.

All developers are encouraged to keep the project free of clang-tidy warnings.

---

# Compiler Warnings

Compiler warnings are enabled from the beginning of the project.

Current warning policy includes:

* `-Wall`
* `-Wextra`
* `-Wpedantic`

Warnings should be treated as defects and resolved rather than ignored.

---

# Sanitizers

Debug builds may enable:

* AddressSanitizer (ASan)
* UndefinedBehaviorSanitizer (UBSan)

Sanitizers are intended to detect memory errors and undefined behavior during development.

Release builds should not enable sanitizers.

---

# CMake Presets

The project uses CMake Presets to provide reproducible build configurations.

Current presets include:

```text
debug-clang
release-clang

debug-gcc
release-gcc
```

Additional presets may be introduced for:

* AddressSanitizer
* UndefinedBehaviorSanitizer
* RelWithDebInfo
* CI-specific builds

---

# Build Directory

All generated files are placed inside the `build/` directory.

Example layout:

```text
build/
├── clang/
│   ├── debug/
│   └── release/
└── gcc/
    ├── debug/
    └── release/
```

Build artifacts should never be committed to version control.

---

# Coding Style

Formatting is enforced through:

* `.clang-format`
* `.editorconfig`

General C++ conventions are described separately in `CodingStyle.md`.

---

# Continuous Integration

GitHub Actions verifies that:

* the project configures successfully;
* the project builds successfully.

Additional automated checks will be introduced over time, including formatting verification, static analysis, testing, and packaging.

---

# Repository Layout

The repository is organized into clearly separated components.

Examples include:

* engine source
* editor
* sandbox application
* documentation
* build configuration

The exact layout is documented in the project's Architecture documentation.

---

# Future Tooling

As development progresses, additional tools will become part of the recommended environment.

Examples include:

* Vulkan SDK
* glslang
* shaderc
* SPIRV-Tools
* RenderDoc
* Tracy Profiler
* Catch2
* Doxygen

These dependencies will be introduced only when they become necessary.

---

# Reproducibility

The project aims to minimize machine-specific configuration.

Builds should rely on:

* CMake Presets
* toolchain files
* repository configuration

rather than user-specific IDE settings or environment variables whenever practical.

---

# Guiding Principle

The development environment should remain simple, deterministic, and reproducible.

Every contributor should be able to clone the repository, configure the project using a CMake preset, and obtain the same build behavior regardless of the development machine.
