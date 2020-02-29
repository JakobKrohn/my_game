#include "Surface/Surface.hpp"

#include <stdexcept>

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

Surface::Surface(const char *imagePath, float sizeFactor)
{
    // m_surface = IMG_Load(imagePath);
    SDL_Surface *surface = IMG_Load(imagePath);
    // SDL_Surface * surface;
    if (surface == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }

    if (sizeFactor > 0.0)
    {
        // SDL_Surface * screenSurface = SDL_GetWindowSurface(window->get());

        // Crop the image
        // SDL_Rect rect;
        // rect.x = 0;
        // rect.y = 0;
        // rect.h = surface->h * sizeFactor;
        // rect.w = surface->w * sizeFactor;
        // auto err = SDL_BlitScaled(m_surface, NULL, m_surface, &rect);
        // if (err < 0)
        //     throw std::runtime_error(SDL_GetError());
        // m_surface = surface;
    }
    // else
        m_surface = surface;

    m_width = m_surface->w;
    m_height = m_surface->h;

    print("Surface '", this, "' created.", "\n\tPath: ", imagePath,
          " \n\tWidth: ", m_width, ", height: ", m_height);
}

Surface::~Surface()
{
    SDL_FreeSurface(m_surface);
    m_surface = nullptr;
    print("Surface '", this, "' destroyed");
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