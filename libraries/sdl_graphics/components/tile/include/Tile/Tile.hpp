#ifndef SDL_TILE_HPP
#define SDL_TILE_HPP

/**
 * 
 * This class will take one image (more in the future) and create a tilemap from it. 
 * 
*/

#include "SDL_image.h"

#include "memory"

#include "Renderer/Renderer.hpp"
#include "Texture/Texture.hpp"

namespace sdl_graphics
{

class Tile
{
public:
    Tile(std::shared_ptr<Renderer> renderer, const char *imagePath);
    Tile(const Tile &tile); 
    Tile(Tile &&tile);
    ~Tile();

    void draw(SDL_Rect tilePos, SDL_Rect windowPos);

    // Get width & height
    std::tuple<const unsigned int &, const unsigned int &> getSize() const;

private:
    std::shared_ptr<Texture> m_texture;
    std::shared_ptr<Renderer> m_renderer;

    unsigned int m_width;
    unsigned int m_height;
};

} // namespace sdl_graphics

#endif // SDL_TILE_HPP