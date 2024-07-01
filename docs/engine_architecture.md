# Game Engine Architecture Documentation

## Table of Contents

1. [Introduction](#introduction)
2. [Directory Structure](#directory-structure)
3. [Detailed Component Description](#detailed-component-description)
   - [assets](#assets)
   - [CMakeLists.txt](#cmakelists.txt)
   - [docs](#docs)
   - [src](#src)
     - [common](#common)
     - [objects](#objects)
     - [scripts](#scripts)
       - [physics](#physics)
       - [rendering](#rendering)
       - [sound](#sound)
       - [texture](#texture)
   - [temp](#temp)
   - [tests](#tests)
4. [Conclusion](#conclusion)

## Introduction

This document provides a detailed overview of the architecture of a game engine based on the structure of Game Maker Studio 1. The aim is to help developers understand the organization and purpose of each component in the engine. This engine is developed in pure C.

### Project Architecture

The architecture of this game engine can be described as a combination of **Modular Architecture**, **Component-Based Architecture**, and **Backend Abstraction Architecture**. This approach is particularly effective for game engine development due to its flexibility, code reuse, and ease of maintenance and scalability.

#### 1. Modular Architecture

The structure clearly separates responsibilities and independent modules. Each module is grouped according to its specific functionality:

- **common**: Contains common utilities and macros that can be used by other modules.
- **objects**: Includes game entities (Entity, Geometry, Object, Player), each with its own implementations.
- **scripts**: Contains submodules for physics, rendering, sound, and textures, with specific implementations for different backends (e.g., Linux, raylib, SDL, Windows).
- **tests**: Contains unit tests for the different modules.

#### 2. Component-Based Architecture

Within the `objects` folder, each game entity (e.g., Entity, Geometry, Object, Player) has its own set of source and header files. This suggests a component-based approach, where each game entity is handled independently, allowing for more flexible and reusable development.

#### 3. Backend Abstraction

The `scripts` folder has subdirectories such as `physics`, `rendering`, `sound`, and `texture`, each with specific backends for different platforms (e.g., Linux, raylib, SDL, Windows). This indicates a design with an abstraction layer that allows different backend systems to be used interchangeably. This technique is common in game engines that need to support multiple platforms.

#### 4. Separation of Test Code

The `tests` directory suggests an architecture that includes unit testing, which is a good practice for maintaining code quality. This separation facilitates the maintenance and testing of different modules in isolation.

#### 5. Use of Build Tools

The `CMakeLists.txt` file suggests the use of CMake as a build tool, which is common in C/C++ projects to handle configuration and generation of build files across multiple platforms.

### Summary

The architecture of this project appears to be a combination of several architectural approaches:

- **Modularity**: Clear separation of responsibilities and grouping of functionalities.
- **Component-Based**: Component-based design for game entities.
- **Abstraction**: Abstraction layer for different backends, facilitating multi-platform support.
- **Testing**: Inclusion of unit tests to ensure code quality.

## Directory Structure

```
├── assets
├── CMakeLists.txt
├── docs
│   └── engine_characteristics.md
├── README.md
├── src
│   ├── common
│   │   ├── ColorUtils
│   │   ├── CommonMacros.h
│   │   ├── CommonMacros.h.in
│   │   └── MemoryUtils
│   │       ├── memory_function_macro_templates.h
│   │       └── utils.h
│   ├── objects
│   │   ├── Entity
│   │   │   ├── Entity.c
│   │   │   └── Entity.h
│   │   ├── Geometry
│   │   │   ├── Geometry.c
│   │   │   └── Geometry.h
│   │   ├── Object
│   │   │   ├── Object.c
│   │   │   └── Object.h
│   │   └── Player
│   │       ├── Player.c
│   │       └── Player.h
│   └── scripts
│       ├── physics
│       │   ├── physics_cleanup.c
│       │   ├── physics_cleanup.h
│       │   ├── physics_init.c
│       │   ├── physics_init.h
│       │   ├── physics_update.c
│       │   └── physics_update.h
│       ├── rendering
│       │   ├── backends
│       │   │   ├── linux
│       │   │   │   ├── render_cleanup.c
│       │   │   │   ├── render_init.c
│       │   │   │   └── render_update.c
│       │   │   ├── raylib
│       │   │   │   ├── render_cleanup.c
│       │   │   │   ├── render_init.c
│       │   │   │   └── render_update.c
│       │   │   ├── sdl
│       │   │   │   ├── render_cleanup.c
│       │   │   │   ├── render_init.c
│       │   │   │   └── render_update.c
│       │   │   └── windows
│       │   │       ├── render_cleanup.c
│       │   │       ├── render_init.c
│       │   │       └── render_update.c
│       │   ├── render_cleanup.h
│       │   ├── render_init.h
│       │   └── render_update.h
│       ├── sound
│       │   ├── backends
│       │   │   ├── linux
│       │   │   │   ├── sound_cleanup.c
│       │   │   │   ├── sound_init.c
│       │   │   │   ├── sound_load.c
│       │   │   │   └── sound_play.c
│       │   │   ├── raylib
│       │   │   │   ├── sound_cleanup.c
│       │   │   │   ├── sound_init.c
│       │   │   │   ├── sound_load.c
│       │   │   │   └── sound_play.c
│       │   │   ├── sdl
│       │   │   │   ├── sound_cleanup.c
│       │   │   │   ├── sound_init.c
│       │   │   │   ├── sound_load.c
│       │   │   │   └── sound_play.c
│       │   │   └── windows
│       │   │       ├── sound_cleanup.c
│       │   │       ├── sound_init.c
│       │   │       ├── sound_load.c
│       │   │       └── sound_play.c
│       │   ├── sound_cleanup.h
│       │   ├── sound_init.h
│       │   ├── sound_load.h
│       │   └── sound_play.h
│       └── texture
│           ├── texture_bind.c
│           ├── texture_bind.h
│           ├── texture_cleanup.c
│           ├── texture_cleanup.h
│           ├── texture_load.c
│           └── texture_load.h
├── temp
│   └── main.c
└── tests
    ├── physics_tests.c
    ├── render_tests.c
    ├── sound_tests.c
    └── texture_tests.c
```

## Detailed Component Description

### assets

The `assets` directory is designated for storing game assets such as images, sounds, and other media files. This is where developers can place all the resources needed by the game.

### CMakeLists.txt

The `CMakeLists.txt` file is used for managing the build process of the game engine. It defines the build configuration, compiles sources, and links libraries. CMake is a cross-platform tool that simplifies the build process.

### docs

The `docs` directory contains documentation files for the game engine. The `engine_characteristics.md` file provides detailed information about the engine's characteristics and features.

### src

The `src` directory holds the source code of the game engine, divided into several subdirectories based on functionality.

#### common

The `common` directory contains utility files and common macros used throughout the engine.

- `ColorUtils`: Utility functions for handling color operations.
- `CommonMacros.h`: Header file defining macros used across the engine.
- `MemoryUtils`: Utilities for memory management.
  - `memory_function_macro_templates.h`: Templates for memory functions.
  - `utils.h`: General memory utility functions.

#### objects

The `objects` directory includes the definitions and implementations of game objects using structures.

- `Entity`: Base entity structure representing any game object.
  - `Entity.c`: Implementation of the Entity structure.
  - `Entity.h`: Header file for the Entity structure.
- `Geometry`: Functions for geometric calculations.
  - `Geometry.c`: Implementation of geometric functions.
  - `Geometry.h`: Header file for geometric functions.
- `Object`: Base object structure for the game.
  - `Object.c`: Implementation of the Object structure.
  - `Object.h`: Header file for the Object structure.
- `Player`: Player-specific functionality.
  - `Player.c`: Implementation of the Player structure.
  - `Player.h`: Header file for the Player structure.

#### scripts

The `scripts` directory contains various scripts organized by functionality.

##### physics

Scripts related to the physics engine.

- `physics_cleanup.c`: Cleanup functions for the physics engine.
- `physics_cleanup.h`: Header file for physics cleanup functions.
- `physics_init.c`: Initialization functions for the physics engine.
- `physics_init.h`: Header file for physics initialization functions.
- `physics_update.c`: Update functions for the physics engine.
- `physics_update.h`: Header file for physics update functions.

##### rendering

Scripts related to the rendering engine, with different backends for various platforms.

- `backends`: Platform-specific rendering scripts.
  - `linux`, `raylib`, `sdl`, `windows`: Directories containing platform-specific rendering scripts.
    - `render_cleanup.c`: Cleanup functions for rendering.
    - `render_init.c`: Initialization functions for rendering.
    - `render_update.c`: Update functions for rendering.
- `render_cleanup.h`: Header file for rendering cleanup functions.
- `render_init.h`: Header file for rendering initialization functions.
- `render_update.h`: Header file for rendering update functions.

##### sound

Scripts related to the sound engine, with different backends for various platforms.

- `backends`: Platform-specific sound scripts.
  - `linux`, `raylib`, `sdl`, `windows`: Directories containing platform-specific sound scripts.
    - `sound_cleanup.c`: Cleanup functions for sound.
    - `sound_init.c`: Initialization functions for sound.
    - `sound_load.c`: Functions for loading sound files.
    - `sound_play.c`: Functions for playing sounds.
- `sound_cleanup.h`: Header file for sound cleanup functions.
- `sound_init.h`: Header file for sound initialization functions.
- `sound_load.h`: Header file for sound loading functions.
- `sound_play.h`: Header file

for sound playing functions.

##### texture

Scripts related to texture management.

- `texture_bind.c`: Functions for binding textures.
- `texture_bind.h`: Header file for texture binding functions.
- `texture_cleanup.c`: Cleanup functions for textures.
- `texture_cleanup.h`: Header file for texture cleanup functions.
- `texture_load.c`: Functions for loading textures.
- `texture_load.h`: Header file for texture loading functions.

### temp

The `temp` directory is used for temporary files and testing purposes. The `main.c` file is typically a temporary main entry point used during development and testing.

### tests

The `tests` directory contains test files for different components of the engine.

- `physics_tests.c`: Tests for the physics engine.
- `render_tests.c`: Tests for the rendering engine.
- `sound_tests.c`: Tests for the sound engine.
- `texture_tests.c`: Tests for texture management.

## Conclusion

This document provides an overview of the architecture of a game engine developed in pure C. By organizing the code into distinct directories and using structures, the engine maintains a clear and modular design, facilitating easier development and maintenance.
