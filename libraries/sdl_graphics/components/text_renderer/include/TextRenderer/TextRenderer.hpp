#ifndef SDL_GRAPHICS_TEXT_RENDERER_HPP
#define SDL_GRAPHICS_TEXT_RENDERER_HPP

#include <string>
#include <memory>

#include "SDL_ttf.h"

#include "Renderer/Renderer.hpp"

namespace sdl_graphics
{

class TextRenderer
{
public:
    TextRenderer(uint posX, uint posY, SDL_Color color, std::shared_ptr<Renderer> renderer);

    void renderText(std::string text);

private:
    std::shared_ptr<Renderer> m_renderer;
    uint m_posX;
    uint m_posY;
    TTF_Font *m_font;
    SDL_Color m_color;
};

} // namespace sdl_graphics

#endif // SDL_GRAPHICS_TEXT_RENDERER_HPP