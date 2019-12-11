#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "SDL.h"

namespace sdl_graphics
{
class Window
{
public:
    Window(uint32_t positionX, uint32_t positionY, uint32_t width, uint32_t height, uint32_t flag);
    ~Window();
private:
    SDL_Window * m_window;
};
} // namespace sdl_graphics

#endif // WINDOW_HPP
