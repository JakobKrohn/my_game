#ifndef GRAPHICS_INTERFACE_TILE_HPP
#define GRAPHICS_INTERFACE_TILE_HPP

#include <memory>

struct TileSize_T
{
    int width;
    int height;
    // TileSize_T(std::shared_ptr<float> w, std::shared_ptr<float> h)
    //     : width(w), height(h)
    // {
    // }
    // TileSize_T() = delete;
    // std::shared_ptr<float> width;
    // std::shared_ptr<float> height;
};

struct TilePosition_T
{
    int x;
    int y;
    int a = 0;
    // TilePosition_T(std::shared_ptr<float> xpos, std::shared_ptr<float> ypos)
    //     : x(xpos), y(ypos)
    // {
    // }
    // TilePosition_T() = delete;
    // std::shared_ptr<float> x;
    // std::shared_ptr<float> y;
};

class Tile_I
{
  public:
    /**
     * Render tile at position
     */
    virtual void draw(TilePosition_T &position) = 0;
    /**
     * Get size (width/height) of tile
     *  Size will be affected is setSize is set
     */
    virtual TileSize_T getSize() const = 0;
    /**
     * Set the size of the tile, based on the original size. 
     *  e.g. 0.5 == 50% of original size
     */
    virtual void setSize(float percent) = 0;
};

#endif