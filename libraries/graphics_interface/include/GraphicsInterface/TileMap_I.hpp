#ifndef GRAPHICS_INTERFACE_TILE_MAP_HPP
#define GRAPHICS_INTERFACE_TILE_MAP_HPP

#include <tuple>

#include "Image_I.hpp"

/**
 * A graphics element to hold one or several images. 
 * Images can be shifted for animation. 
 */
class TileMap_I
{
public:
    virtual ~TileMap_I() {}

    // TODO: Pass width and height
    virtual void resizeEvent(uint32_t &width, uint32_t &height) = 0;

    // Draw tilemap
    virtual void draw() = 0;

    // Get number of tiles on screen [horizontal, vertical]
    virtual std::tuple<const unsigned int &, const unsigned int &> getNumberOfTiles() const = 0;

    virtual float &getHorizontalGround() = 0;

    virtual float &getVerticalGround() = 0;
};

#endif // GRAPHICS_INTERFACE_TILE_MAP_HPP
