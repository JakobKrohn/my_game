#include "Image/Image.hpp"
#include <iostream>
using namespace sdl_graphics;

Image::Image(std::shared_ptr<Renderer> renderer,
             std::shared_ptr<Image_I> drawable)
{
    m_renderer = renderer;
    m_drawable = drawable;
    SDL_Surface *loadedSurface = IMG_Load(m_drawable->getImagePath().c_str());

    if (loadedSurface == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }

    m_texture = SDL_CreateTextureFromSurface(m_renderer->get(), loadedSurface);

    SDL_FreeSurface(loadedSurface);

    if (m_texture == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }
}

// Vector calls copy constructor when it grows:
// https://stackoverflow.com/a/40457433
Image::Image(const Image &image) : Image(image.m_renderer, image.m_drawable)
{
}

Image::~Image()
{
    SDL_DestroyTexture(m_texture);
}

void Image::draw()
{
    m_rect.h = m_drawable->getHeight();
    m_rect.w = m_drawable->getWidth();
    m_rect.x = m_drawable->getPosX();
    m_rect.y = m_drawable->getPosY();
    auto size = m_drawable->getSizeToDraw();
    SDL_Rect *sizeRect = nullptr;
    if (size.has_value())
    {
        sizeRect = new SDL_Rect; // Delete me after!!
        sizeRect->h = size->h;
        sizeRect->w = size->w;
        sizeRect->x = size->x;
        sizeRect->y = size->y;
    }
    SDL_RenderCopyEx(m_renderer->get(), m_texture, sizeRect, &m_rect,
                     m_drawable->getAngle(), NULL, SDL_FLIP_NONE);
}