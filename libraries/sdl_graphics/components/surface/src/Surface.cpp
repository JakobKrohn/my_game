#include "Surface/Surface.hpp"

#include <stdexcept>

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

Surface::Surface(const char *imagePath)
{
    m_surface = IMG_Load(imagePath);
    if (m_surface == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }

    m_width = m_surface->w;
    m_height = m_surface->h;
}

Surface::~Surface()
{
    SDL_FreeSurface(m_surface);
    m_surface = nullptr;
}

SDL_Surface *Surface::get() const
{
    return m_surface;
}

void Surface::getSize(unsigned int &width, unsigned int &height)
{
    width = m_width;
    height = m_height;
}