# Box Head

## Clone repo with submodules
$ git clone --recursive <url/ssh>
<br>

## Prerequisite
- Cmake
- Ninja
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
2. https://github.com/onqtam/doctest 

### TODO: 

- std::string_view and const char *, no strings
- Error handling: runtime_error catching
- Resize event should reposition and redraw all elements
- F11 should open fullscreen
- Draw a bigger frame
- Rewrite textrenderer for perfomance
- Moving background
- Fix Drawable_T types. 
- Detect window out of focus - pause game
- Clean up textrenderer class.
- https://github.com/grimfang4/SDL_FontCache/blob/master/SDL_FontCache.h 
