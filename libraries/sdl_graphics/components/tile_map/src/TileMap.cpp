#include "TileMap/TileMap.hpp"

#include <cmath>

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

TileMap::TileMap(uint32_t &windowWidth, uint32_t &windowHeight, Tile &&tile)
    : m_tile(std::move(tile)), m_horizontalTiles(0), m_verticalTiles(0),
      m_horizontalGround(0), m_verticalGround(0), m_verticalOffset(0),
      m_horizontalOffset(0), m_windowWidth(windowWidth),
      m_windowHeight(windowHeight)
{
    print("TileMap ", this, " created");
    resizeEvent(windowWidth, windowHeight);
}

void TileMap::resizeEvent(uint32_t &width, uint32_t &height)
{
    print("TileMap resize event");
    m_windowWidth = width;
    m_windowHeight = height;
    auto size = m_tile.getSize();

    m_verticalGround = 0;
    m_horizontalGround = 0;

    m_windowPos.x = (int)m_horizontalGround;
    m_windowPos.y = (int)m_verticalGround;
    m_windowPos.h = size.height;
    m_windowPos.w = size.width;

    m_tilePos.x = 0;
    m_tilePos.y = 0;
    m_tilePos.h = size.height;
    m_tilePos.w = size.width;

    m_horizontalTiles = ceil((double)width / (double)size.width);
    m_verticalTiles = ceil((double)height / (double)size.height);

    m_verticalOffset = ((size.height * m_verticalTiles) - height) /
                       (m_verticalTiles -
                        (m_verticalTiles > 2 ? floor(m_verticalTiles / 2) : 0));

    m_horizontalOffset =
        ((size.width * m_horizontalTiles) - width) /
        (m_horizontalTiles -
         (m_horizontalTiles > 2 ? floor(m_horizontalTiles / 2) : 0));
}

void TileMap::draw()
{
    m_windowPos.y = m_verticalGround;
    m_windowPos.x = m_horizontalGround;
    handleNumberOfTiles();

    for (unsigned int i = 0; i < m_verticalTiles; i++)
    {
        m_windowPos.y = m_verticalGround;
        m_windowPos.y += (m_tilePos.h * i) - m_verticalOffset;
        for (unsigned int i = 0; i < m_horizontalTiles; i++)
        {
            m_windowPos.x = m_horizontalGround;
            m_windowPos.x += (m_tilePos.w * i) - m_horizontalOffset;

            TilePosition_T tilePos = {m_windowPos.x, m_windowPos.y};
            m_tile.draw(tilePos);
        }
    }
}

std::tuple<const unsigned int &, const unsigned int &>
TileMap::getNumberOfTiles() const
{
    return std::forward_as_tuple(m_horizontalTiles, m_verticalTiles);
}

float &TileMap::getHorizontalGround()
{
    return m_horizontalGround;
}

float &TileMap::getVerticalGround()
{
    return m_verticalGround;
}

void TileMap::handleNumberOfTiles()
{
    addHorizontalTiles();
    addVerticalTiles();
    removeTiles();
}

void TileMap::addHorizontalTiles()
{
    /**
     * The first time adding a horizontal tile, when moving to the left,
     * this first check will set m_horizontalOffset to -478. This will result in
     * one frame with wrong tile positions.
     *
     */
    unsigned int check = (m_horizontalTiles * m_tilePos.w) -
                         m_horizontalOffset +
                         (int)m_horizontalGround; // TODO Possibly ceil
    if (check <= m_windowWidth)
    {
        m_horizontalTiles++;
        m_horizontalOffset -= m_tilePos.w;
    }

    /**
     * This check will set the m_horizontalOffset back to correct.
     */
    if (m_horizontalGround >= m_horizontalOffset)
    {
        m_horizontalTiles++;
        m_horizontalOffset += m_tilePos.w;
    }
}

void TileMap::addVerticalTiles()
{
    /**
     * See comment in addHorizontalTiles() function.
     * Same applies here.
     */
    unsigned int check = (m_verticalTiles * m_tilePos.h) - m_verticalOffset +
                         (int)m_verticalGround;
    if (check < m_windowHeight)
    {
        m_verticalTiles++;
        m_verticalOffset -= m_tilePos.h;
    }

    if (m_verticalGround > m_verticalOffset)
    {
        m_verticalTiles++;
        m_verticalOffset += m_tilePos.h;
    }
}

void TileMap::removeTiles()
{

    // Right
    if ((m_horizontalTiles * m_tilePos.w) - m_tilePos.w * 2 > m_windowWidth)
    {
        m_horizontalTiles--;
    }

    // Bottom
    if ((m_verticalTiles * m_tilePos.h) - m_tilePos.h * 2 > m_windowHeight)
    {
        m_verticalTiles--;
    }
}