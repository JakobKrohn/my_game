#include "Image/Image.hpp"

using namespace sdl_graphics;

Image::Image(std::shared_ptr<Renderer> renderer, std::shared_ptr<SdlImage_I> drawable)
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

Image::Image(std::shared_ptr<Renderer> renderer, std::vector<std::shared_ptr<SdlImage_I>> images)
{
    //std::map<std::shared_ptr<SdlImage_I>, *SDL_Texture> m_drawables;
    m_renderer = renderer;

    for (const auto &img : images)
    {
        SDL_Surface *surface = IMG_Load(img->getImagePath().c_str());
        if (surface == nullptr)
        {
            throw std::runtime_error(IMG_GetError());
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer->get(), surface);
        if (texture == nullptr)
        {
            throw std::runtime_error(IMG_GetError());
        }
    }
}

Image::Image(std::shared_ptr<Renderer> renderer, std::shared_ptr<SdlElement_I> element)
{
    // std::map<std::shared_ptr<SdlImage_I>, SDL_Texture*> m_drawables;
    m_renderer = renderer;
    m_element = element;
    auto images = element->getImages();
    for (const auto &img : images)
    {
        SDL_Surface *surface = IMG_Load(img->getImagePath().c_str());
        if (surface == nullptr)
        {
            throw std::runtime_error(IMG_GetError());
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer->get(), surface);
        if (texture == nullptr)
        {
            throw std::runtime_error(IMG_GetError());
        }

        m_textures.emplace_back(texture);
        // m_drawables.insert(std::pair<std::shared_ptr<SdlImage_I>, SDL_Texture*>(img, texture));
    }
}

void Image::draw()
{
    auto img = m_element->getCurrentImage();
    m_rect.h = img->getHeight();
    m_rect.w = img->getWidth();
    m_rect.x = img->getPosX();
    m_rect.y = img->getPosY();
    
    // m_rect.h = m_drawable->getHeight();
    // m_rect.w = m_drawable->getWidth();
    // m_rect.x = m_drawable->getPosX();
    // m_rect.y = m_drawable->getPosY();

    SDL_RenderCopyEx(m_renderer->get(), m_textures.at(0), NULL, &m_rect, img->getAngle(), NULL, SDL_FLIP_NONE);
    // SDL_RenderCopyEx(m_renderer->get(), m_texture, NULL, &m_rect, m_drawable->getAngle(), NULL, SDL_FLIP_NONE);
}