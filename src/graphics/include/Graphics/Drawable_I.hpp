#ifndef DRAWABLE_INTERFACE_HPP
#define DRAWABLE_INTERFACE_HPP

#include <string>

namespace graphics
{

struct Drawable_T
{
    std::string imagePath; // TODO: const
    uint16_t width;
    uint16_t height;
    uint32_t posX;
    uint32_t posY;
    uint16_t angle;
};

class Drawable_I
{
public:
    virtual const std::string getImagePath() const = 0;
    virtual uint16_t getWidth() const = 0;
    virtual uint16_t getHeight() const = 0;
    virtual uint32_t getPosX() const = 0;
    virtual uint32_t getPosY() const = 0;
    virtual uint16_t getAngle() const = 0;
};

} // namespace graphics

#endif // DRAWABLE_INTERFACE_HPP