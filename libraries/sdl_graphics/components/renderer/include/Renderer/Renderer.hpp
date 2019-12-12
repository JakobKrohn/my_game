#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <memory>

#include "SDL.h"

#include "Window/Window.hpp"

namespace sdl_graphics
{
class Renderer
{
public:
    Renderer(std::shared_ptr<Window> window, int index, uint32_t flag);
    ~Renderer();
private:
    SDL_Renderer * m_renderer;
};
} // namespace sdl_graphics

#endif // RENDERER_HPP