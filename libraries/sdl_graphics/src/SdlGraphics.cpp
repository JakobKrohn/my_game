#include "SdlGraphics/SdlGraphics.hpp"

using namespace sdl_graphics;

void SdlGraphics::createWindow(unsigned int windowPosX, unsigned int windowPosY)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error(SDL_GetError());
    }

    m_window = std::make_shared<Window>(windowPosX, windowPosY, 500, 500, SDL_WINDOW_SHOWN);
    m_renderer = std::make_unique<Renderer>(m_window, -1, SDL_RENDERER_ACCELERATED);
}

void SdlGraphics::update()
{

}

void SdlGraphics::addElement(std::shared_ptr<graphics::Drawable_I> element)
{
    m_elements.push_back(element);
}