# Configuración de SDL2_image y SDL2_ttf en Dev C++

Este documento proporciona una guía paso a paso sobre cómo configurar SDL2_image y SDL2_ttf en Dev C++.

## Prerrequisitos

- Dev C++ (versión 5.11 o superior recomendada)
- SDL2 ya configurado en tu proyecto. Si no lo has hecho, sigue las instrucciones para instalar SDL2 [aquí](https://github.com/tu-usuario/tu-repositorio).

## Descarga de SDL2_image y SDL2_ttf

1. Ve a la página de descargas de SDL:
   - [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
   - [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)

2. Descarga las versiones `Development Libraries` para Windows (`SDL2_image-devel-2.x.x-VC.zip` y `SDL2_ttf-devel-2.x.x-VC.zip`).

## Instalación de SDL2_image

1. Extrae el contenido del archivo `SDL2_image-devel-2.x.x-VC.zip`.

2. Copia los archivos en las carpetas correspondientes de tu instalación de SDL2:
   - Copia los archivos `.dll` de la carpeta `lib` a la carpeta `lib` de tu instalación de SDL2.
   - Copia los archivos `.h` de la carpeta `include` a la carpeta `include` de tu instalación de SDL2.
   - Copia los archivos `.lib` de la carpeta `lib` a la carpeta `lib` de tu instalación de SDL2.

3. En Dev C++, abre tu proyecto y ve a **Proyecto > Opciones del proyecto > Parámetros**.
   - En la pestaña **Linker**, añade las siguientes bibliotecas: `SDL2_image.lib`.
   - En la pestaña **Compilador**, añade la ruta a los archivos `.h` de SDL2_image en **Directorios C++ > Añadir**.

## Instalación de SDL2_ttf

1. Extrae el contenido del archivo `SDL2_ttf-devel-2.x.x-VC.zip`.

2. Copia los archivos en las carpetas correspondientes de tu instalación de SDL2:
   - Copia los archivos `.dll` de la carpeta `lib` a la carpeta `lib` de tu instalación de SDL2.
   - Copia los archivos `.h` de la carpeta `include` a la carpeta `include` de tu instalación de SDL2.
   - Copia los archivos `.lib` de la carpeta `lib` a la carpeta `lib` de tu instalación de SDL2.

3. En Dev C++, abre tu proyecto y ve a **Proyecto > Opciones del proyecto > Parámetros**.
   - En la pestaña **Linker**, añade las siguientes bibliotecas: `SDL2_ttf.lib`.
   - En la pestaña **Compilador**, añade la ruta a los archivos `.h` de SDL2_ttf en **Directorios C++ > Añadir**.

## Configuración Adicional

- Asegúrate de que las bibliotecas dinámicas (`.dll`) estén en la misma carpeta que tu ejecutable al ejecutar el programa.

## Ejemplo de Código

A continuación, se muestra un ejemplo básico de cómo inicializar y usar SDL2_image y SDL2_ttf:

```cpp
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "Error al inicializar SDL_image: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Error al inicializar SDL_ttf: " << TTF_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Código para crear ventanas, cargar imágenes y fuentes...

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
