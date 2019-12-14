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

    SDL_Renderer *getSdlObject() const;

    void setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
    void clear();
    void present();

private:
    SDL_Renderer *m_renderer;
};
} // namespace sdl_graphics

#endif // RENDERER_HPP