cmake_minimum_required(VERSION 3.10)
project(GameEngine)

# Options for selecting rendering backend
option(USE_SDL "Use SDL for rendering" OFF)
option(USE_RAYLIB "Use RayLib for rendering" OFF)
option(USE_WINAPI "Use WinAPI for rendering" OFF)
option(USE_X11 "Use X11 for rendering" OFF)

# Options for selecting sound backend
option(USE_SDL_SOUND "Use SDL for sound" OFF)
option(USE_RAYLIB_SOUND "Use RayLib for sound" OFF)
option(USE_OPENAL "Use OpenAL for sound" OFF)

# Option to build shared or static libraries
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

# Output directories for libraries and executables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(src)

# Define EXPORT macro based on BUILD_SHARED_LIBS
if (BUILD_SHARED_LIBS)
    add_definitions(-DEXPORT_GUB_LIB=extern)
else()
    add_definitions(-DEXPORT_GUB_LIB=)
endif()

# Sources for the GameEngine library
set(GAME_ENGINE_SOURCES
    src/objects/Entity/Entity.c
    src/objects/Object/Object.c
    src/objects/Player/Player.c
    
    src/scripts/physics/physics_init.c
    src/scripts/physics/physics_update.c
    src/scripts/physics/physics_cleanup.c

    src/scripts/texture/texture_bind.c
    src/scripts/texture/texture_load.c
    src/scripts/texture/texture_cleanup.c
)

# Configure selected rendering backend
if (USE_SDL)
    add_definitions(-DUSE_SDL)
    list(APPEND GAME_ENGINE_SOURCES
        src/scripts/rendering/backends/sdl/render_init.c
        src/scripts/rendering/backends/sdl/render_update.c
        src/scripts/rendering/backends/sdl/render_cleanup.c
    )
elseif (USE_RAYLIB)
    add_definitions(-DUSE_RAYLIB)
    list(APPEND GAME_ENGINE_SOURCES
        src/scripts/rendering/backends/raylib/render_init.c
        src/scripts/rendering/backends/raylib/render_update.c
        src/scripts/rendering/backends/raylib/render_cleanup.c
    )
elseif (USE_WINAPI)
    add_definitions(-DUSE_WINAPI)
    list(APPEND GAME_ENGINE_SOURCES
        src/scripts/rendering/backends/windows/render_init.c
        src/scripts/rendering/backends/windows/render_update.c
        src/scripts/rendering/backends/windows/render_cleanup.c
    )
elseif (USE_X11)
    add_definitions(-DUSE_X11)
    list(APPEND GAME_ENGINE_SOURCES
        src/scripts/rendering/backends/linux/render_init.c
        src/scripts/rendering/backends/linux/render_update.c
        src/scripts/rendering/backends/linux/render_cleanup.c
    )
else ()
    message(FATAL_ERROR "No rendering backend selected")
endif ()

# Configure selected sound backend
if (USE_SDL_SOUND)
    add_definitions(-DUSE_SDL_SOUND)
    list(APPEND GAME_ENGINE_SOURCES
        src/scripts/sound/backends/sdl/sound_init.c
        src/scripts/sound/backends/sdl/sound_load.c
        src/scripts/sound/backends/sdl/sound_play.c
        src/scripts/sound/backends/sdl/sound_cleanup.c
    )
elseif (USE_RAYLIB_SOUND)
    add_definitions(-DUSE_RAYLIB_SOUND)
    list(APPEND GAME_ENGINE_SOURCES
        src/scripts/sound/backends/raylib/sound_init.c
        src/scripts/sound/backends/raylib/sound_load.c
        src/scripts/sound/backends/raylib/sound_play.c
        src/scripts/sound/backends/raylib/sound_cleanup.c
    )
elseif (USE_OPENAL)
    add_definitions(-DUSE_OPENAL)
    list(APPEND GAME_ENGINE_SOURCES
        src/scripts/sound/backends/openal/sound_init.c
        src/scripts/sound/backends/openal/sound_load.c
        src/scripts/sound/backends/openal/sound_play.c
        src/scripts/sound/backends/openal/sound_cleanup.c
    )
else ()
    message(FATAL_ERROR "No sound backend selected")
endif ()

# GameEngine library
if (BUILD_SHARED_LIBS)
    if (WIN32)
        add_library(GameEngine SHARED ${GAME_ENGINE_SOURCES})
        set_target_properties(GameEngine PROPERTIES SUFFIX ".dll")
    elseif (UNIX)
        add_library(GameEngine SHARED ${GAME_ENGINE_SOURCES})
        set_target_properties(GameEngine PROPERTIES SUFFIX ".so")
    endif ()
else ()
    add_library(GameEngine STATIC ${GAME_ENGINE_SOURCES})
    set_target_properties(GameEngine PROPERTIES SUFFIX ".a")
endif ()

# Copy header files to 'include' directory in 'lib' output directory
file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/src/*.h")
foreach(header ${HEADER_FILES})
    get_filename_component(header_path ${header} DIRECTORY)
    string(REPLACE "${CMAKE_SOURCE_DIR}/src" "" header_path ${header_path})
    set(dest "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/include${header_path}")
    file(MAKE_DIRECTORY ${dest})
    configure_file(${header} ${dest}/${header} COPYONLY)
endforeach()
