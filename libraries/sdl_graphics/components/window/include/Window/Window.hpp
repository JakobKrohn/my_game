#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "SDL.h"

// #include "Types.hpp"

// https://wiki.libsdl.org/SDL_WindowFlags

namespace sdl_graphics
{

struct WindowPosition
{
    uint16_t x_begin;
    uint16_t y_begin;
    uint16_t x_end;
    uint16_t y_end;
};

struct WindowSize
{
    uint16_t width;
    uint16_t height;
};

class Window
{
  public:
    Window(uint16_t positionX, uint16_t positionY, uint16_t width,
           uint16_t height, uint32_t flag);
    ~Window();

    SDL_Window *get() const;

  private:
    SDL_Window *m_window;
    WindowPosition m_position;
};

} // namespace sdl_graphics

#endif // WINDOW_HPP
