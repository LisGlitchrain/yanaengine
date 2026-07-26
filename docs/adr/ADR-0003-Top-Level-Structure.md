# ADR-0003 — Top-Level Structure

**Status:** Accepted
**Date:** 2026-07-26

---

## Context

Yana Engine is intended to be a long-term educational project focused on modern C++, graphics programming, and engine architecture.

The project needs a top-level structure that keeps responsibilities clear while allowing the architecture to evolve over time as practical experience reveals better solutions.

The structure must support:

* a reusable engine runtime;
* a separate executable host;
* an application layer that controls runtime behavior;
* a game project containing assets and gameplay content;
* editor tooling that can begin as project content plus engine plugins and later evolve if needed;
* live editing during development;
* full reload from a clean state when needed.

The design should also remain flexible enough to change if real usage shows that a decision is causing significant problems.

---

## Decision

The top-level architecture will be organized around the following concepts:

### Host

The **Host** is the executable entry point.

It is responsible for:

* process startup;
* platform-specific initialization;
* command-line parsing;
* selecting which application mode to run;
* creating and driving the engine lifecycle;
* forwarding operating system events to the engine;
* handling shutdown and exit codes.

The Host is platform-specific and remains thin.

---

### Engine

The **Engine** is a reusable library.

It is responsible for the runtime systems that are shared by all application modes, including:

* core utilities;
* platform abstraction;
* timing and frame control;
* input;
* rendering;
* scene and world management;
* asset loading;
* event dispatch;
* other reusable runtime systems added later.

The Engine must not depend on the Host executable, game-specific content, or editor tooling internals.

---

### Application

The **Application** is a library layer parallel to the Engine and dependent on it.

It defines the behavior or mode that the engine should run.

Examples include:

* game application;
* editor application;
* sandbox application;
* later, possibly server or headless modes.

The Application layer is responsible for:

* configuring what the engine should do at startup;
* selecting and wiring the appropriate systems and modules;
* deciding how the runtime behaves during update and shutdown;
* coordinating higher-level flow without owning low-level engine implementation details.

---

### Game Project

The **Game Project** contains game-specific assets, scripts, configuration, and gameplay content.

It may later also contain compiled gameplay modules, but conceptually it represents the project being run by the engine.

This includes:

* scenes;
* configuration files;
* scripts;
* data assets;
* gameplay content;
* project-specific resources.

The Game Project is not the engine itself.

---

### Editor Tools

The **Editor Tools** layer initially starts as additional project assets plus engine plugins.

Examples may include:

* editor UI;
* scene hierarchy;
* inspector;
* gizmos;
* asset browser;
* console;
* profiling tools.

This layer may evolve later into a more formal editor application or separate editor module structure if needed.

---

## Live Editing and Reload

The project will support live editing during development.

However, live editing must not become the only way to update the running runtime.

A full reload path must exist in which the engine:

1. shuts down current runtime state,
2. reinitializes systems from scratch,
3. reloads project data,
4. starts again from a clean state.

This provides both:

* fast iteration during development;
* reproducible runtime behavior when needed.

The clean reload path is considered a first-class feature, not an optional fallback.

---

## Evolution Policy

These architectural decisions are accepted as the current design, but they are not permanent.

If practical use reveals a critical problem, the architecture may be revised.

Important changes should be recorded as new ADRs rather than silently altering the original decision.

This allows the project to evolve deliberately while preserving the reasoning behind past choices.

---

## Consequences

### Positive

* Clear separation between executable, runtime, behavior, content, and tooling.
* Engine remains reusable and easier to test.
* Application modes can evolve independently.
* Editor tooling can start simple and grow later.
* Live editing and reproducible reload behavior can coexist.
* Architecture remains flexible enough to change over time.

### Negative

* More concepts must be understood before implementation begins.
* Some boundaries are still provisional and may be refined later.
* Editor structure may require refactoring as the project grows.
* Additional discipline is needed to keep engine, application, and project content separated.

These trade-offs are acceptable for a project whose main goal is learning and long-term maintainability.

---

## Alternatives Considered

### Single executable with all logic inside it

Rejected.

This would blur boundaries between engine, editor, and game, and would make future reuse harder.

---

### Engine as both library and executable identity

Rejected.

The engine should remain reusable and not be tied to a specific executable role.

---

### Editor as a separate monolithic application from the beginning

Deferred.

The editor may eventually become its own application, but starting with lighter editor tooling keeps the project simpler and easier to evolve.

---

### Pure live-editing without full reload

Rejected.

Live editing alone can produce hidden state drift and reduce reproducibility. A clean reload path is required.

---

## Notes

This ADR intentionally defines the top-level structure in a way that supports future refactoring.

The goal is not to freeze the architecture permanently.

The goal is to establish a clear starting point that can survive early development while remaining open to improvement.
