#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "SDL.h"

#include "Types.hpp"

namespace sdl_graphics
{

class Window
{
public:
    Window(uint16_t positionX, uint16_t positionY, uint16_t width, uint16_t height, uint32_t flag);
    ~Window();

    SDL_Window *get() const;

private:
    SDL_Window *m_window;
    WindowPosition m_position;
    // WindowSize m_size;
};

} // namespace sdl_graphics

#endif // WINDOW_HPP
