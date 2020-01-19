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
    ~Tile();

private:
    unsigned int m_width;
    unsigned int m_height;

    std::shared_ptr<Texture> m_texture;

};

} // namespace sdl_graphics

#endif // SDL_TILE_HPP