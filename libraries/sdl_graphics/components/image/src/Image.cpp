#include "Image/Image.hpp"

using namespace sdl_graphics;

Image::Image(std::shared_ptr<Renderer> renderer, std::shared_ptr<graphics::Drawable> drawable)
{
    m_renderer = renderer;
    m_drawable = drawable;
    SDL_Surface *loadedSurface = IMG_Load(drawable->getImagePath().c_str());

    if (loadedSurface == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }

    m_texture = SDL_CreateTextureFromSurface(m_renderer->getSdlObject(), loadedSurface);

    if (m_texture == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }
}

void Image::draw()
{
    SDL_RenderCopy(m_renderer->getSdlObject(), m_texture, NULL, NULL);
}