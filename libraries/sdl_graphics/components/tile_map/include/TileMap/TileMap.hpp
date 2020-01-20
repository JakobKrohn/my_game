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
    TileMap(std::shared_ptr<Renderer> renderer, Tile tile);
    // TODO destructor

    void draw();

    std::tuple<const unsigned int &, const unsigned int &> getNumberOfTiles() const;

    int& getHorizontalGround();

    int& getVerticalGround();

private:
    std::shared_ptr<Renderer> m_renderer;
    Tile *m_tile; // todo free
    unsigned int m_horizontalTiles;
    unsigned int m_verticalTiles;
    int m_horizontalGround;
    int m_verticalGround;
};

} // namespace sdl_graphics

#endif // SDL_TILE_MAP