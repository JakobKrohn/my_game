#include "SdlGraphics/SdlGraphics.hpp"

using namespace sdl_graphics;

void SdlGraphics::createWindow(unsigned int windowPosX, unsigned int windowPosY)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error(SDL_GetError());
    }

    m_window = std::make_unique<Window>(windowPosX, windowPosY, 500, 500, SDL_WINDOW_SHOWN);
}

void SdlGraphics::update()
{

}

void SdlGraphics::addElement(std::shared_ptr<graphics::Drawable_I> element)
{
    m_elements.push_back(element);
}