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

    // Draw tilemap
    virtual void draw() = 0;

    // Get number of tiles on screen [horizontal, vertical]
    virtual std::tuple<const unsigned int &, const unsigned int &> getNumberOfTiles() const = 0;

    virtual int& getHorizontalGround() = 0;

    virtual int& getVerticalGround() = 0;
};

#endif // GRAPHICS_INTERFACE_TILE_MAP_HPP
