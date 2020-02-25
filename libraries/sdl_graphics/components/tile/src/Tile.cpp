#include "Tile/Tile.hpp"

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

Tile::Tile(std::shared_ptr<Renderer> renderer, const char *imagePath)
    : m_texture(nullptr), m_renderer(nullptr), m_width(0), m_height(0)
{
    m_renderer = renderer;
    m_texture = std::make_shared<Texture>(m_renderer, imagePath);

    m_width = m_texture->getWidth();
    m_height = m_texture->getHeight();

    print("Tile [", this, "] created.", "\n\tPath: ", imagePath,
          " \n\tWidth: ", m_width, ", height: ", m_height);
}

Tile::Tile(const Tile &tile)
    : m_texture(nullptr), m_renderer(nullptr), m_width(0), m_height(0)
{
    m_renderer = tile.m_renderer;
    m_texture = tile.m_texture;
    m_width = m_texture->getWidth();
    m_height = m_texture->getHeight();
    print("Tile [", this, "] copied.", " \n\tWidth: ", m_width,
          ", height: ", m_height);
}

Tile::Tile(Tile &&tile)
    : m_texture(tile.m_texture), m_renderer(tile.m_renderer),
      m_width(tile.m_texture->getWidth()), m_height(tile.m_texture->getHeight())
{
    print("Tile [", this, "] moved.", " \n\tWidth: ", m_width,
          ", height: ", m_height);
}

Tile::~Tile()
{
    print("Tile '", this, "' destroyed");
}

void Tile::draw(SDL_Rect tilePos, SDL_Rect windowPos)
{
    SDL_RenderCopyEx(m_renderer->get(), m_texture->get(), &tilePos, &windowPos,
                     0, NULL, SDL_FLIP_NONE);
}

std::tuple<const unsigned int &, const unsigned int &> Tile::getSize() const
{
    return std::forward_as_tuple(m_width, m_height);
}