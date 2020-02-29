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

    if (sizeFactor > 0.0)
        setSize(sizeFactor);
}

Tile::Tile(const Tile &tile)
    : Tile(tile.m_renderer, tile.m_imagePath, tile.m_sizeFactor)
{
}

Tile::Tile(Tile &&tile)
    : Tile(tile.m_renderer, tile.m_imagePath, tile.m_sizeFactor)
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
    print("Setting size: \n\tOriginal width: ", m_size.width,
          "\n\tOriginal height: ", m_size.height,
          "\n\tNew width: ", m_texture->getWidth() * percent,
          "\n\tNew height: ", m_texture->getHeight() * percent);
    auto newWidth = m_texture->getWidth() * percent;
    auto newHeight = m_texture->getHeight() * percent;

    // m_tilePos.x = m_size.width - newWidth / 2;
    // m_tilePos.y = m_size.height - newHeight / 2;
    // m_windowPos.x = m_size.width - newWidth;
    // m_windowPos.y = m_size.height - newHeight;

    m_size.height = newHeight;
    m_size.width = newWidth;

    m_windowPos.h = m_size.height;
    m_windowPos.w = m_size.width;

    m_tilePos.h = m_size.height;
    m_tilePos.w = m_size.width;

    m_tilePos.x = (m_texture->getWidth() - m_size.width) / 2;
    m_tilePos.y = (m_texture->getHeight() - m_size.height) / 2;
    // m_tilePos.x = m_texture->getWidth() - m_size.width * 1.5;
    // m_tilePos.y = m_texture->getHeight() - m_size.height * 1.5;
    print("\tX/Y: ", m_tilePos.x, "/", m_tilePos.y);
    // m_tilePos.x = m_size.width / 2;
    // m_tilePos.y = m_size.height / 2;
}