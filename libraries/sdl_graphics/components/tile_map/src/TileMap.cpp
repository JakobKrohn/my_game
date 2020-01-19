#include "TileMap/TileMap.hpp"

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

TileMap::TileMap(std::shared_ptr<Renderer> renderer, Tile tile)
{
    m_renderer = renderer;
    m_tile = new Tile(tile);
    print("TileMap ", this, " created");
}

void TileMap::draw()
{
    auto[width, height] = m_renderer->getWindowSize();

    auto[tileWidth, tileHeight] = m_tile->getSize();

    if (tileWidth * 2 < width)
    {
        // Needs > 3 tiles 
    }

    if (tileHeight * 2 < height)
    {
        // Needs > 3 tiles
    }

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

    // TOP LEFT

    m_tile->draw(tilePos, windowPos);

    // TOP RIGHT

    windowPos.x = tileWidth;
    windowPos.y = 0;
    
    m_tile->draw(tilePos, windowPos);

    // BOTTOM LEFT

    windowPos.x = 0;
    windowPos.y = tileHeight;

    m_tile->draw(tilePos, windowPos);

    // BOTTOM RIGHT

    windowPos.x = tileWidth;
    windowPos.y = tileHeight;

    m_tile->draw(tilePos, windowPos);
}