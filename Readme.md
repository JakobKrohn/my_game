# Box Head

## Prerequisite
- Cmake
- SDL2
- SDL2 image
- SDL2 ttf

#### Install Cmake
Download cmake from https://cmake.org/download/
Version 3.15 or higher. 

### Install SDL2 
$ sudo apt install libsdl2-dev 

### Install SDL2 image
$ sudo apt-get install libsdl2-image-dev

### Install SDL2 TTF
$ sudo apt-get install libsdl2-ttf-dev

### Modules
1. https://github.com/tcbrindle/sdl2-cmake-scripts

### TODO: 

- TileMap, Rezise event not working correctly
- Texture
- Surface

- volatile
- nullptr checking
- std::string_view and const char *, no strings
- Error handling: runtime_error catching
- F11 should open fullscreen
- Rewrite textrenderer for perfomance
- Fix Drawable_T types. 
- Detect window out of focus - pause game
- Clean up textrenderer class.
- https://github.com/grimfang4/SDL_FontCache/blob/master/SDL_FontCache.h 

### Open art
- https://opengameart.org/content/backgrounds-topdown-games 

### Format all
    find src/ libraries/ test/ application/ -iname *.hpp -o -iname *.cpp | xargs clang-format -i
