#include "Image/Image.hpp"

using namespace sdl_graphics;

Image::Image(std::shared_ptr<Renderer> renderer, std::shared_ptr<graphics::Drawable_I> drawable)
{
    m_renderer = renderer;
    m_drawable = drawable;
    SDL_Surface *loadedSurface = IMG_Load(drawable->getImagePath().c_str());

    if (loadedSurface == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }

    m_texture = SDL_CreateTextureFromSurface(m_renderer->get(), loadedSurface);

    if (m_texture == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }

    m_rect.h = drawable->getHeight();
    m_rect.w = drawable->getWidth();
    m_rect.x = drawable->getPosX();
    m_rect.y = drawable->getPosY();

}

void Image::draw()
{
    m_rect.h = m_drawable->getHeight();
    m_rect.w = m_drawable->getWidth();
    m_rect.x = m_drawable->getPosX();
    m_rect.y = m_drawable->getPosY();
    SDL_RenderCopyEx(m_renderer->get(), m_texture, NULL, &m_rect, m_drawable->getAngle(), NULL, SDL_FLIP_NONE);
}