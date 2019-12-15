#include "SdlGraphics/SdlGraphics.hpp"

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

SdlGraphics::SdlGraphics(unsigned int windowPosX, unsigned int windowPosY)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        throw std::runtime_error(IMG_GetError());
    }

    m_window = std::make_shared<Window>(windowPosX, windowPosY, 640, 580, SDL_WINDOW_SHOWN);
    // m_renderer = std::make_shared<Renderer>(m_window, -1, SDL_RENDERER_ACCELERATED);
    m_renderer = std::make_shared<Renderer>(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

    m_renderer->setColor(0x00, 0x00, 0x00);
    m_renderer->clear();
    m_renderer->present();
}

void SdlGraphics::update()
{
    m_renderer->setColor(0x00, 0x00, 0x00);
    m_renderer->clear();

    for (auto &element : m_elements)
    {
        element.second.draw();
    }

    m_renderer->present();
}

void SdlGraphics::addElement(std::shared_ptr<graphics::Drawable_I> element)
{
    Image image(m_renderer, element);
    m_elements.push_back(std::make_pair(element, image));
}
