#include "TileMap/TileMap.hpp"

#include <cmath>

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

TileMap::TileMap(uint32_t &windowWidth, uint32_t &windowHeight, Tile tile)
    : m_tile(nullptr),
      m_horizontalTiles(0),
      m_verticalTiles(0),
      m_horizontalGround(0),
      m_verticalGround(0),
      m_verticalOffset(0),
      m_horizontalOffset(0), 
      m_windowWidth(windowWidth), 
      m_windowHeight(windowHeight)
{
    m_tile = new Tile(tile); // TODO - not like this..
    print("TileMap ", this, " created");
    resizeEvent(windowWidth, windowHeight);
}

void TileMap::resizeEvent(uint32_t &width, uint32_t &height)
{
    m_windowWidth = width;
    m_windowHeight = height;
    print("TileMap resize event");
    auto [tileWidth, tileHeight] = m_tile->getSize();

    m_windowPos.x = m_horizontalGround;
    m_windowPos.y = m_verticalGround;
    m_windowPos.h = tileHeight;
    m_windowPos.w = tileWidth;

    m_tilePos.x = 0;
    m_tilePos.y = 0;
    m_tilePos.h = tileHeight;
    m_tilePos.w = tileWidth;

    m_horizontalTiles = ceil((double)width / (double)tileWidth);
    m_verticalTiles = ceil((double)height / (double)tileHeight);

    m_verticalOffset = ((tileHeight * m_verticalTiles) - height) / (m_verticalTiles - (m_verticalTiles > 2 ? floor(m_verticalTiles / 2) : 0));
    m_horizontalOffset = ((tileWidth * m_horizontalTiles) - width) / (m_horizontalTiles - (m_horizontalTiles > 2 ? floor(m_horizontalTiles / 2) : 0));
}

void TileMap::draw()
{
    // Check left add
    if (m_horizontalGround > m_horizontalOffset)
    {
        m_horizontalTiles++;
        m_horizontalOffset += m_tilePos.w;
    }

    // Check right remove
    if ((m_horizontalTiles * m_tilePos.w) - m_tilePos.w * 2 > m_windowWidth)
    {
        m_horizontalTiles--;
    }

    // Check right add right
    auto check = (m_horizontalTiles * m_tilePos.w) - m_horizontalOffset + m_horizontalGround;
    if (check < m_windowWidth)
    {
        m_horizontalTiles++;
        m_horizontalOffset -= m_tilePos.w;
    }

    // Check top add
    if (m_verticalGround > m_verticalOffset)
    {
        m_verticalTiles++;
        m_verticalOffset += m_tilePos.h;
    }

    // Check bottom remove
    if ((m_verticalTiles * m_tilePos.h) - m_tilePos.h * 2 > m_windowHeight)
    {
        m_verticalTiles--;
    }

    // Check bottom add
    check = (m_verticalTiles * m_tilePos.h) - m_verticalOffset + m_verticalGround;
    if (check < m_windowHeight)
    {
        m_verticalTiles++;
        m_verticalOffset -= m_tilePos.h;
    }

    // Draw
    for (unsigned int i = 0; i < m_verticalTiles; i++)
    {
        m_windowPos.y = m_verticalGround;
        m_windowPos.y += (m_tilePos.h * i) - m_verticalOffset;

        for (unsigned int i = 0; i < m_horizontalTiles; i++)
        {
            m_windowPos.x = m_horizontalGround;
            m_windowPos.x += (m_tilePos.w * i) - m_horizontalOffset;

            m_tile->draw(m_tilePos, m_windowPos);
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

void TileMap::checkTile(SDL_Rect pos)
{
    // Left side
    if (pos.x < 0 &&
        pos.y < 0 &&
        pos.x + pos.h < 0 &&
        pos.y + pos.w < 0)
    {
        std::cout << "outside left\n";
    }
}
