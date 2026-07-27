# ADR-0004: Time Architecture

## Status

Accepted

---

## Context

Time is one of the fundamental services of every game engine.

Many engine systems depend on time:

* game loop
* animation
* physics
* rendering
* particle systems
* audio
* networking
* editor
* profiling

Different engines expose time differently.

* Unity exposes a global static `Time` class.
* Unreal passes `DeltaSeconds` explicitly to tick functions.
* Godot passes `delta` to `_process()` and `_physics_process()`.
* CryEngine provides a central timer service through the engine environment.

The goal of Yana Engine is to combine the strengths of these approaches while keeping the lowest-level utilities reusable outside of the engine.

---

## Decision

The time system is divided into two layers.

### Layer 1 — Generic Time Utilities

The Core module provides generic, reusable C++ utilities built on top of `std::chrono`.

Examples include:

* `Timer`
* `Stopwatch`
* future clock helpers

Structure:
```text
Core
 └── Time
      ├── Clock
      ├── Stopwatch
      └── Timer

Runtime
 └── EngineClock

Scripting
 └── Time facade
```

These utilities:

* have no knowledge of the engine
* have no knowledge of scenes
* have no knowledge of rendering
* have no knowledge of the game loop

They are ordinary C++ libraries that can be reused in:

* tools
* asset pipelines
* benchmarks
* command line applications
* other engines

This layer answers questions such as:

> "How much time elapsed since this timer started?"

---

### Layer 2 — Engine Clock

The engine owns one authoritative runtime clock.

The Engine Clock is responsible for maintaining runtime information such as:

* frame delta time
* elapsed engine time
* frame count
* time scale
* pause state

The Engine updates the Engine Clock exactly once every frame.

This layer answers questions such as:

> "How much game time passed during the previous frame?"

---

## Explicit Time Propagation

Engine subsystems receive elapsed frame time explicitly.

Example:

```cpp
engine.Tick(deltaTime);

scene.Tick(deltaTime);

entity.Tick(deltaTime);
```

This follows the philosophy used by Unreal Engine and Godot.

Advantages:

* dependencies are explicit
* code is easier to test
* hidden global state is reduced
* multiple clocks become possible in the future

---

## Scripting API

While engine code receives time explicitly, scripting languages should expose convenient accessors similar to Unity.

Examples:

```cpp
Time.deltaTime
Time.frameCount
Time.elapsedTime
```

These values are read from the Engine Clock.

This provides a familiar scripting experience while keeping the engine internals independent from global state.

---

## Rationale

### Why not a global static Time class?

A single global object eventually becomes responsible for many unrelated concepts:

* real time
* game time
* editor time
* replay time
* physics time
* animation time

As the engine grows, these concepts become increasingly difficult to separate.

---

### Why not pass Timer objects everywhere?

A generic timer measures elapsed duration.

It should not know anything about:

* game state
* pause
* frame timing
* time scaling

Those responsibilities belong to the Engine Clock.

---

### Why explicit delta propagation?

Passing `deltaTime` explicitly makes function dependencies obvious.

Instead of hidden state:

```cpp
position += velocity * Time.deltaTime;
```

engine code uses:

```cpp
position += velocity * deltaTime;
```

The caller decides which clock is being used.

This allows future support for:

* editor simulation
* replay systems
* multiple worlds
* independent simulation clocks

without changing subsystem APIs.

---

## Consequences

### Advantages

* Clear separation between reusable utilities and engine runtime.
* Engine internals remain independent from global state.
* Easier testing.
* Easier support for multiple clocks.
* Generic time utilities can be published as standalone C++ libraries.
* Scripting remains simple and familiar.

### Disadvantages

* Engine code must pass `deltaTime` through subsystem APIs.
* Two layers of abstraction require slightly more initial implementation.
* Beginners may find explicit time propagation less convenient than a global singleton.

---

## Future Extensions

The architecture allows future additions without breaking existing code.

Possible future components include:

* `FrameClock`
* `GameClock`
* `PhysicsClock`
* `EditorClock`
* `AnimationClock`
* `NetworkClock`
* `ProfilerClock`

Each represents a distinct concept rather than extending a single monolithic `Time` object.

---

## Decision Summary

Yana Engine adopts a layered time architecture.

* Generic time utilities provide reusable measurement primitives.
* The Engine owns an authoritative Engine Clock.
* Engine systems receive `deltaTime` explicitly.
* Scripting exposes Unity-like convenience properties backed by the Engine Clock.

This combines the strengths of Unity, Unreal Engine, Godot, and CryEngine while preserving modularity, testability, and library reusability.
