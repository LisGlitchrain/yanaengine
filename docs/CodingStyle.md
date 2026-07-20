# Coding Style

## Goals

The code should be:

- Easy to read.
- Easy to maintain.
- Easy to refactor.
- Consistent.

Readability is preferred over cleverness.

---

## Language

- C++23
- Modern CMake
- UTF-8 source files

---

## Formatting

Formatting is performed automatically using clang-format.

Manual formatting should not be relied upon.

---

## Naming

(To be decided.)

Examples:

- PascalCase?
- camelCase?
- snake_case?

These conventions will be established before writing production code.

---

## Comments

Comments should explain **why**, not **what**.

Bad:

```cpp
// Increment i
++i;
```

Good:
```cpp
// Skip the root node because it is processed separately.
++i;
```

General Principles
- Prefer RAII.
- Prefer const.
- Prefer standard library facilities.
- Avoid macros unless necessary.
- Avoid global state.

