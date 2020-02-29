#ifndef SDL_TILE_HPP
#define SDL_TILE_HPP

/**
 *
 * This class will take one image (more in the future) and create a tilemap from
 * it.
 *
 */

#include "SDL_image.h"

#include "memory"

#include "GraphicsInterface/Tile_I.hpp"
#include "Renderer/Renderer.hpp"
#include "Texture/Texture.hpp"

namespace sdl_graphics
{

class Tile : public Tile_I
{
  public:
    Tile(std::shared_ptr<Renderer> renderer, const char *imagePath, float size);
    Tile(const Tile &tile); // Never called (yet)
    Tile(Tile &&tile);
    ~Tile();

    // Tile_I
    void draw(TilePosition_T &position);
    TileSize_T getSize() const;
    void setSize(float percent);

  private:
    std::shared_ptr<Texture> m_texture;
    std::shared_ptr<Renderer> m_renderer;
    const char * m_imagePath;
    float m_sizeFactor;

    TileSize_T m_size;

    SDL_Rect m_tilePos;
    SDL_Rect m_windowPos;
};

} // namespace sdl_graphics

#endif // SDL_TILE_HPP