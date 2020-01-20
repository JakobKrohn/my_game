#include "TileMap/TileMap.hpp"

#include <cmath>

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

TileMap::TileMap(std::shared_ptr<Renderer> renderer, Tile tile)
{
    m_renderer = renderer;
    m_tile = new Tile(tile); // TODO - not like this..
    print("TileMap ", this, " created");
}

void TileMap::draw()
{
    auto[windowWith, windowHeight] = m_renderer->getWindowSize();

    auto[tileWidth, tileHeight] = m_tile->getSize();

    SDL_Rect windowPos;
    windowPos.x = 0;
    windowPos.y = 0;
    windowPos.h = tileHeight;
    windowPos.w = tileWidth;

    SDL_Rect tilePos;
    tilePos.x = 0;
    tilePos.y = 0;
    tilePos.h = tileHeight;
    tilePos.w = tileWidth;

    m_horizontalTiles = ceil( (double)windowWith / (double)tileWidth );
    m_verticalTiles =   ceil( (double)windowHeight / (double)tileHeight );

    long verticalOffset = ( (tileWidth * m_verticalTiles) - windowHeight ) / m_verticalTiles;
    int horisontalOffset = ( (tileWidth * m_horizontalTiles) - windowWith ) / m_horizontalTiles;

    for (int i = 0; i < m_verticalTiles; i++)
    {
        windowPos.y = (tileHeight * i) - verticalOffset;

        for (int i = 0; i < m_horizontalTiles; i++)
        {
            windowPos.x = (tileWidth * i) - horisontalOffset;
            m_tile->draw(tilePos, windowPos);
        }
    }
}