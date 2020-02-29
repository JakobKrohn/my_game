#include "Tile/Tile.hpp"

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

Tile::Tile(std::shared_ptr<Renderer> renderer, const char *imagePath,
           float sizeFactor)
    : m_texture(nullptr), m_renderer(nullptr), m_imagePath(imagePath),
      m_sizeFactor(sizeFactor)
{
    m_renderer = renderer;
    m_texture = std::make_shared<Texture>(m_renderer, imagePath, sizeFactor);

    m_size.width = m_texture->getWidth();
    m_size.height = m_texture->getHeight();

    m_tilePos.h = m_size.height;
    m_tilePos.w = m_size.width;
    m_tilePos.x = 0;
    m_tilePos.y = 0;

    m_windowPos.h = m_size.height;
    m_windowPos.w = m_size.width;
    m_windowPos.x = 0;
    m_windowPos.y = 0;
}

Tile::Tile(const Tile &tile)
    : Tile(tile.m_renderer, tile.m_imagePath, tile.m_sizeFactor)
{
}

Tile::Tile(Tile &&tile) : Tile(tile.m_renderer, tile.m_imagePath, tile.m_sizeFactor)
{
}

Tile::~Tile()
{
    print("Tile '", this, "' destroyed");
}

void Tile::draw(TilePosition_T &position)
{
    m_windowPos.x = position.x;
    m_windowPos.y = position.y;

    SDL_RenderCopyEx(m_renderer->get(), m_texture->get(), &m_tilePos,
                     &m_windowPos, 0, NULL, SDL_FLIP_NONE);
}

TileSize_T Tile::getSize() const
{
    return m_size;
}

void Tile::setSize(float percent)
{
    auto newWidth = m_size.width * percent;
    auto newHeight = m_size.height * percent;

    m_texture->resize(newWidth, newHeight);

    m_size.height = newHeight;
    m_size.width = newWidth;
    m_windowPos.h = m_size.height;
    m_windowPos.w = m_size.width;
    m_tilePos.h = m_size.height;
    m_tilePos.w = m_size.width;
}