#ifndef GRAPHICS_INTERFACE_IMAGE_HPP
#define GRAPHICS_INTERFACE_IMAGE_HPP

#include <string>
#include <memory>

class Image_I
{
public:
    virtual ~Image_I() {}

    // Get image asset path
    virtual const std::string getImagePath() const = 0;

    // Get pointer to width of the image
    virtual uint32_t getWidth() const = 0;

    // Get height of the image
    virtual uint32_t getHeight() const = 0;

    // Get the X position for the image
    virtual uint32_t getPosX() const = 0;

    // Get the Y position for the image
    virtual uint32_t getPosY() const = 0;

    // Get the angle for the image
    virtual uint16_t getAngle() const = 0;
};

#endif // GRAPHICS_INTERFACE_IMAGE_HPP