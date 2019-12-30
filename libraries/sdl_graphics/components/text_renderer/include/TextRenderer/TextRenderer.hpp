#ifndef SDL_GRAPHICS_TEXT_RENDERER_HPP
#define SDL_GRAPHICS_TEXT_RENDERER_HPP

#include <string>
#include <memory>

#include "SDL_ttf.h"

#include "Renderer/Renderer.hpp"
#include "Window/Window.hpp"

namespace sdl_graphics
{

enum class TextLocation
{
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT,
    FLOATING
};

class TextRenderer
{
public:
    TextRenderer(uint posX, uint posY, SDL_Color color, std::shared_ptr<Renderer> renderer);

    TextRenderer(std::string fontPath, uint8_t fontSize, std::shared_ptr<Renderer> renderer);

    // Too many arguments.
    // TextRenderer(TextLocation location, SDL_Color textColor, SDL_Color backgroundColor, std::string fontPath, uint8_t fontSize, std::shared_ptr<Renderer> renderer, std::shared_ptr<Window> window);

    void setLocation(TextLocation location);
    void setTextColor(SDL_Color color);
    void setBackgroundColor(SDL_Color color);
    void setPadding(uint8_t padding);

    void render(std::string text);
    void renderText(std::string text);

private:
    std::shared_ptr<Renderer> m_renderer;
    uint m_posX;
    uint m_posY;
    TTF_Font *m_font;
    SDL_Color m_color;
    SDL_Color m_backgroundColor;
    TextLocation m_location;
    uint8_t m_padding;

    // Calculate Width(X) & Height(Y) position
    std::tuple<uint, uint> calculatePosition(uint textWidth, uint textHeight);
};

} // namespace sdl_graphics

#endif // SDL_GRAPHICS_TEXT_RENDERER_HPP