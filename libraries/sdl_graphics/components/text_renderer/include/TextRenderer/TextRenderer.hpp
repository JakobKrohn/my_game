#ifndef SDL_GRAPHICS_TEXT_RENDERER_HPP
#define SDL_GRAPHICS_TEXT_RENDERER_HPP

#include <string>
#include <memory>

#include "SDL_ttf.h"

#include "GraphicsInterface/Text_I.hpp"
#include "Renderer/Renderer.hpp"
#include "Window/Window.hpp"

namespace sdl_graphics
{

class TextRenderer : public Text_I
{
public:
    TextRenderer(std::string fontPath, uint8_t fontSize, std::shared_ptr<Renderer> renderer);
    ~TextRenderer();

    //Text_I
    void draw();
    void setText(std::string text);
    void setTextColor(Color_T color);
    void setLocation(TextLocation location);
    void drawBackground(bool mode);
    void setBackground(uint16_t width, uint16_t height, Color_T color);

    // In case of resize event
    void reposition();

private:
    std::shared_ptr<Renderer> m_renderer;
    TextLocation m_location;
    TTF_Font *m_font;
    SDL_Color m_color;
    SDL_Color m_backgroundColor;
    bool m_drawBackground;
    SDL_Rect m_background;
    SDL_Rect m_textRect;
    SDL_Texture *m_texture;
    std::string m_text;

    // Calculate Width(X) & Height(Y) position
    std::tuple<uint, uint> calculatePosition(uint textWidth, uint textHeight);
};

} // namespace sdl_graphics

#endif // SDL_GRAPHICS_TEXT_RENDERER_HPP