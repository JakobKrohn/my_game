#include "TileMap/TileMap.hpp"

#include <cmath>

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

TileMap::TileMap(std::shared_ptr<Renderer> renderer, Tile tile)
    : m_renderer(renderer),
      m_tile(nullptr),
      m_horizontalTiles(0),
      m_verticalTiles(0),
      m_horizontalGround(0),
      m_verticalGround(0)
{
    m_tile = new Tile(tile); // TODO - not like this..
    print("TileMap ", this, " created");
}

void TileMap::draw()
{
    auto [windowWith, windowHeight] = m_renderer->getWindowSize();

    auto [tileWidth, tileHeight] = m_tile->getSize();

    SDL_Rect windowPos;
    windowPos.x = m_horizontalGround;
    windowPos.y = m_verticalGround;
    windowPos.h = tileHeight;
    windowPos.w = tileWidth;

    SDL_Rect tilePos;
    tilePos.x = 0;
    tilePos.y = 0;
    tilePos.h = tileHeight;
    tilePos.w = tileWidth;

    m_horizontalTiles = ceil((double)windowWith / (double)tileWidth);
    m_verticalTiles = ceil((double)windowHeight / (double)tileHeight);

    int verticalOffset = ((tileHeight * m_verticalTiles) - windowHeight) / (m_verticalTiles - (m_verticalTiles > 2 ? floor(m_verticalTiles / 2) : 0));
    int horizontalOffset = ((tileWidth * m_horizontalTiles) - windowWith) / (m_horizontalTiles - (m_horizontalTiles > 2 ? floor(m_horizontalTiles / 2) : 0));

    std::cout << m_horizontalGround << "\n";

    for (unsigned int i = 0; i < m_verticalTiles; i++)
    {
        windowPos.y = m_verticalGround;
        windowPos.y += (tileHeight * i) - verticalOffset;

        for (unsigned int i = 0; i < m_horizontalTiles; i++)
        {
            windowPos.x = m_horizontalGround;
            windowPos.x += (tileWidth * i) - horizontalOffset;
            m_tile->draw(tilePos, windowPos);
        }
    }
}

std::tuple<const unsigned int &, const unsigned int &> TileMap::getNumberOfTiles() const
{
    return std::forward_as_tuple(m_horizontalTiles, m_verticalTiles);
}

int &TileMap::getHorizontalGround()
{
    return m_horizontalGround;
}

int &TileMap::getVerticalGround()
{
    return m_verticalGround;
}