#ifndef SDL_GRAPHICS_HPP
#define SDL_GRAPHICS_HPP

#include <vector>
#include <memory>

#include "SDL.h"
#include "SDL_image.h"

#include "Graphics/Graphics_I.hpp"

#include "Window/Window.hpp"
#include "Renderer/Renderer.hpp"

namespace sdl_graphics
{
class SdlGraphics : public graphics::Graphics_I
{
public:
    void createWindow(unsigned int windowPositionX = 0, unsigned int windowPositionY = 0);
    void update();
    void addElement(std::shared_ptr<graphics::Drawable_I> element);

private:
    std::shared_ptr<Window> m_window;
    std::unique_ptr<Renderer> m_renderer;
    std::vector<std::shared_ptr<graphics::Drawable_I>> m_elements;

};
} // namespace sdl_graphics

#endif // SDL_GRAPHICS_HPP
