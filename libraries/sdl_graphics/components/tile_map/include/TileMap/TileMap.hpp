#ifndef SDL_TILE_MAP
#define SDL_TILE_MAP

#include <memory>

#include "Tile/Tile.hpp"
#include "Renderer/Renderer.hpp"

namespace sdl_graphics
{

class TileMap
{
public:
    TileMap(std::shared_ptr<Renderer> renderer, Tile tile);

    void draw();

private:
    std::shared_ptr<Renderer> m_renderer;
    Tile *m_tile; // todo free
};

} // namespace sdl_graphics

#endif // SDL_TILE_MAP