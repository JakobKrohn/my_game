#ifndef SDL_TILE_MAP
#define SDL_TILE_MAP

#include <memory>

#include "GraphicsInterface/TileMap_I.hpp"
#include "Tile/Tile.hpp"
#include "Renderer/Renderer.hpp"

namespace sdl_graphics
{

class TileMap : public TileMap_I
{
public:
    TileMap(uint32_t &windowWidth, uint32_t &windowHeight, Tile tile);     // TODO: No need for renderer!
    // TODO destructor

    void resizeEvent(uint32_t &width, uint32_t &height);

    void draw();

    std::tuple<const unsigned int &, const unsigned int &> getNumberOfTiles() const;

    int& getHorizontalGround();

    int& getVerticalGround();

private:
    Tile *m_tile; // todo free
    unsigned int m_horizontalTiles;
    unsigned int m_verticalTiles;
    int m_horizontalGround;
    int m_verticalGround;
    int m_verticalOffset;
    int m_horizontalOffset;
    uint32_t m_windowWidth;
    uint32_t m_windowHeight;

    SDL_Rect m_windowPos;
    SDL_Rect m_tilePos;

    void checkTile(SDL_Rect pos);
};

} // namespace sdl_graphics

#endif // SDL_TILE_MAP