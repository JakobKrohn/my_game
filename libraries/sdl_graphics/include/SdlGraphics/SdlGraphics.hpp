#ifndef SDL_GRAPHICS_HPP
#define SDL_GRAPHICS_HPP

#include <vector>
#include <memory>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Graphics/Graphics_I.hpp"

#include "Window/Window.hpp"
#include "Renderer/Renderer.hpp"
#include "Image/Image.hpp"

namespace sdl_graphics
{
class SdlGraphics : public graphics::Graphics_I
{
public:
    SdlGraphics(unsigned int windowPositionX = 0, unsigned int windowPositionY = 0);

    void update();
    void addElement(std::shared_ptr<graphics::Drawable_I> element);

private:
    std::shared_ptr<Window> m_window;
    std::shared_ptr<Renderer> m_renderer;
    std::vector<std::pair<std::shared_ptr<graphics::Drawable_I>, Image>> m_elements;
    uint32_t m_countedFrames;
    uint32_t m_startTicks;
    TTF_Font *m_font;
};
} // namespace sdl_graphics

#endif // SDL_GRAPHICS_HPP
