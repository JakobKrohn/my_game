#include "Texture/Texture.hpp"

#include "Logger/Logger.hpp"
#include "Surface/Surface.hpp"

using namespace sdl_graphics;

Texture::Texture(std::shared_ptr<Renderer> renderer, const char *imagePath, float sizeFactor)
    : m_texture(nullptr), m_sizeFactor(sizeFactor), m_width(0), m_height(0)
{
    Surface surface(imagePath, sizeFactor);
    surface.getSize(m_width, m_height);

    m_texture = SDL_CreateTextureFromSurface(renderer->get(), surface.get());
    if (m_texture == nullptr)
    {
        throw std::runtime_error(IMG_GetError());
    }

    print("Texture '", this, "' created.", "\n\tPath: ", imagePath,
          " \n\tWidth: ", m_width, ", height: ", m_height);
}

Texture::~Texture()
{
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
    print("Texture '", this, "' destroyed");
}

SDL_Texture *Texture::get() const
{
    return m_texture;
}

void Texture::resize(uint width, uint height)
{
    // m_texture.reset(SDL_CreateTexture)
}

const unsigned int &Texture::getWidth() const
{
    return m_width;
}
const unsigned int &Texture::getHeight() const
{
    return m_height;
}