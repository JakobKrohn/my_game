#ifndef GRAPHICS_INTERFACE_SPRITE_HPP
#define GRAPHICS_INTERFACE_SPRITE_HPP

#include <memory>
#include <vector>

/**
 * Sprite will hold several images (tiles).
 *  To simulate movement, several sequences can be added, such as:
 *      - Movement sequence
 *      - Shooting sequence
 *      - Still sequence
 *  Each sequence can be one or more images.
 *
 *  Sprite will shift thru all the images added for the current sequence.
 */
class Sprite_I
{
  public:
    /**
     * Add a sequence, for example all images when moving
     * 
     * Returns an ID used to set the current sequence to draw
     */
    virtual unsigned int addSequence(std::vector<const char *> assets) = 0;
    /**
     * Sets the current sequence to render.
     */
    virtual void setCurrentSequence(unsigned int sequence) = 0;
    /**
     * Sets the position pointers
     *  x = x position
     *  y = y position
     *  a = angle
     */
    virtual void setPosition(std::shared_ptr<float> x, std::shared_ptr<float> y,
                             std::shared_ptr<float> a) = 0;
    /**
     * Set the time interval for how long each image will be drawn, 
     *  before it is shifted. 
     * TODO: ms or us?
     */
    virtual void setTimeInterval(int ms, int sequence = -1) = 0;
};

#endif // GRAPHICS_INTERFACE_SPRITE_HPP