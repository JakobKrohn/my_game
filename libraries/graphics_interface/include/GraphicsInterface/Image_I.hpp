#ifndef GRAPHICS_INTERFACE_IMAGE_HPP
#define GRAPHICS_INTERFACE_IMAGE_HPP

#include <memory>
#include <optional>
#include <string>

// X, Y, W, H
struct ImageSize_T
{
    uint32_t x;
    uint32_t y;
    uint32_t w;
    uint32_t h;
    // std::shared_ptr<uint32_t> x;
    // std::shared_ptr<uint32_t> y;
    // std::shared_ptr<uint32_t> w;
    // std::shared_ptr<uint32_t> h;
};

class Image_I
{
  public:
    virtual ~Image_I()
    {
    }

    // Get image asset path
    virtual const std::string getImagePath() const = 0;

    // Get pointer to width of the image
    virtual uint32_t getWidth() const = 0; // ImageSize_T

    // Get height of the image
    virtual uint32_t getHeight() const = 0; // ImageSize_T

    // Get the X position for the image
    virtual uint32_t getPosX() const = 0; // ImageSize_T

    // Get the Y position for the image
    virtual uint32_t getPosY() const = 0; // ImageSize_T

    // Get the angle for the image
    virtual uint16_t getAngle() const = 0;

    // Get the size of the image to draw
    virtual std::optional<ImageSize_T> &getSizeToDraw() const = 0;
};

#endif // GRAPHICS_INTERFACE_IMAGE_HPP