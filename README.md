# GUB Cross Game Engine

## Introducción

GUB Cross es un motor de videojuegos desarrollado en C, basado en la arquitectura GMS 1. Utiliza el patrón Facade para ofrecer soporte multiplataforma mediante la implementación de backends de renderizado y sonido a través de diferentes APIs correspondientes a las plataformas soportadas.

## Arquitectura General

### Patrón Facade

GUB Cross utiliza el patrón Facade para abstraer las diferentes APIs de backend, facilitando así el desarrollo multiplataforma y la integración con la arquitectura GMS 1.

## Componentes Principales

### Backend de Renderizado

GUB Cross implementa backends de renderizado utilizando APIs específicas para cada plataforma, como SDL, RayLib, etc.

### Backend de Sonido

El motor soporta múltiples APIs de sonido para asegurar compatibilidad con diversas plataformas.

## Soporte Multiplataforma

GUB Cross está diseñado para ser compatible con varias plataformas, incluyendo [lista de plataformas soportadas].

# Requerimientos para Compilar

## Linux

- CMake 3.10 o superior
- Compilador GCC o Clang
- Librerías de desarrollo para las APIs seleccionadas, debe tener instalada la librería seleccionada para compilar el motor:
  - SDL (`libsdl2-dev`)
  - RayLib (`libraylib-dev`)
  - X11 (`libx11-dev`)
  - OpenAL (`libopenal-dev`)

## Windows

- CMake 3.10 o superior
- MinGW o MinGW_W64 (compilador GCC para Windows)
- Librerías de desarrollo para las APIs seleccionadas, debe tener instalada la librería seleccionada para compilar el motor:
  - SDL (`SDL2-devel`)
  - RayLib (`raylib`)
  - OpenAL (`openal-soft`)

# Compilación

## Linux

1. Crear directorio `build`:

   ```sh
   mkdir build/
   cd build/
   ```

2. Ejecutar `cmake`:

   **Nota:** Cambia `SDL` por la plataforma o librería con la cual quieras compilar el motor.

   Para compilar como librería compartida:

   ```sh
   cmake -D USE_SDL=ON -D USE_SDL_SOUND=ON ..
   ```

   Para compilar como librería estática:

   ```sh
   cmake -D USE_SDL=ON -D USE_SDL_SOUND=ON -D BUILD_SHARED_LIBS=OFF ..
   ```

3. Ejecutar `make`:

   ```sh
   make
   ```

   Esto generará dentro de `build` un directorio `lib` con la librería compilada.

## Windows (MinGW)

1. Crear directorio `build`:

   ```sh
   mkdir build
   cd build
   ```

2. Ejecutar `cmake`:

   **Nota:** Cambia `SDL` por la plataforma o librería con la cual quieras compilar el motor.

   Para compilar como librería compartida:

   ```sh
   cmake -D USE_SDL=ON -D USE_SDL_SOUND=ON .. -G "MinGW Makefiles"
   ```

   Para compilar como librería estática:

   ```sh
   cmake -D USE_SDL=ON -D USE_SDL_SOUND=ON -D BUILD_SHARED_LIBS=OFF .. -G "MinGW Makefiles"
   ```

3. Ejecutar `mingw32-make`:

   ```sh
   mingw32-make
   ```

   Esto generará dentro de `build` un directorio `lib` con la librería compilada.

## Uso y Ejemplos

Para iniciar un proyecto con GUB Cross, sigue los siguientes pasos:

1. [Instrucciones de instalación]
2. [Configuración básica del proyecto]
3. [Ejemplos de uso en diferentes plataformas]

## Contribuciones y Desarrollo

¡Agradecemos tu interés en contribuir al proyecto GUB Cross! Por favor sigue nuestras [directrices de contribución] y [código de conducta] para mantener un ambiente colaborativo.

## Problemas Conocidos y Limitaciones

### Problemas Conocidos

1. [Lista de problemas conocidos]
2. [Limitaciones actuales]

## Referencias y Recursos Adicionales

- Repositorio de código: [enlace al repositorio]
- Documentación de APIs utilizadas: [enlace a la documentación de APIs]

---
