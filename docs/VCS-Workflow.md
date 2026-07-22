# VCS Workflow

## Purpose

This document describes the recommended Git workflow for **Yana Engine**.

The project follows a **trunk-based development** model with short-lived feature branches.

The goals of this workflow are:

* Keep the repository history clean and easy to understand.
* Ensure the `main` branch is always in a working state.
* Keep every change small and reviewable.
* Make continuous integration simple and reliable.
* Follow modern development practices commonly used in open-source software.

---

# Branches

## `main`

The `main` branch is the primary development branch.

It should always:

* compile successfully;
* pass all configured CI checks;
* represent the latest stable development state.

Development is performed directly from `main` using short-lived feature branches.

There is **no permanent `develop` branch**.

---

# Feature branches

Every task starts by creating a feature branch from the latest `main`.

Naming convention:

```text
feature/<issue-number>-<short-description>
```

Examples:

```text
feature/1-build-system
feature/2-application
feature/5-window
feature/12-vulkan-instance
feature/24-scene-serialization
```

Guidelines:

* use lowercase letters;
* separate words with hyphens;
* keep names concise;
* include the issue number whenever possible.

Feature branches should be short-lived.

After merging into `main`, the feature branch should be deleted.

---

# Other branch types

For non-feature work the following prefixes may be used.

## Bug fixes

```text
bugfix/<issue-number>-<description>
```

Example:

```text
bugfix/42-memory-leak
```

---

## Refactoring

```text
refactor/<issue-number>-<description>
```

Example:

```text
refactor/18-render-graph
```

---

## Documentation

```text
docs/<issue-number>-<description>
```

Example:

```text
docs/7-roadmap-update
```

---

# Workflow

Typical development cycle:

```text
main
 │
 ├── Pull latest changes
 │
 ├── Create feature branch
 │
 ├── Implement the change
 │
 ├── Commit locally
 │
 ├── Push feature branch
 │
 ├── Open Pull Request
 │
 ├── GitHub Actions
 │
 ├── Review
 │
 └── Squash & Merge into main
```

---

# Pull Requests

Every completed feature should be merged through a Pull Request, even for solo development.

Reasons:

* provides a convenient overview of the entire change;
* automatically runs GitHub Actions;
* encourages reviewing the implementation before merging;
* documents the reasoning behind changes;
* keeps project history easier to navigate.

The Pull Request description should reference the related issue whenever applicable.

---

# Commit messages

Commit messages should describe **what** the change introduces.

Preferred style:

```text
Add compiler warning configuration

Create Application class

Implement window abstraction

Introduce logging system

Add Vulkan instance initialization
```

Avoid vague messages such as:

```text
Fix stuff

Update

Changes

Misc
```

---

# Squash merge

Feature branches should normally be merged using **Squash and Merge**.

Advantages:

* one logical commit per completed feature;
* cleaner project history;
* easier to revert an entire feature if necessary;
* keeps intermediate "work in progress" commits out of `main`.

---

# Issues

Every significant task should have a GitHub Issue.

Issues represent planned work.

Examples:

* Configure compiler warnings
* Implement Application class
* Create Window abstraction
* Initialize Vulkan instance

Feature branches should generally correspond to a single issue.

---

# Milestones

Issues should be grouped into milestones representing larger development goals.

Example:

Milestone 1 — Development Infrastructure

* Configure CMake
* Configure compiler warnings
* Configure clang-tidy
* Configure GitHub Actions

Milestone 2 — Application Framework

* Application class
* Engine class
* Logging
* Assertions

Milestones provide a high-level roadmap while issues represent individual implementation tasks.

---

# Continuous Integration

Every Pull Request should pass all configured GitHub Actions before being merged.

Initially, CI verifies that the project:

* configures successfully;
* builds successfully.

Additional checks such as formatting, static analysis, unit tests, sanitizers, and packaging will be added as the engine evolves.

---

# Philosophy

The repository history should tell the story of the engine's evolution.

Each merged feature should represent one meaningful improvement to the project.

Small, focused changes are preferred over large, unrelated commits.

The objective is to make the repository easy to understand months or years later, both for future contributors and for the future self of the project's author.
