#ifndef GRAPHICS_INTERFACE_GRAPHICS_HPP
#define GRAPHICS_INTERFACE_GRAPHICS_HPP

#include <functional>
#include <memory>

#include "Element_I.hpp"
#include "Image_I.hpp"
#include "Text_I.hpp"
#include "TileMap_I.hpp"

/**
 * Interface for graphics libraries
 */
class Graphics_I
{
  public:
    virtual ~Graphics_I()
    {
    }

    // Render objects and update window
    virtual void update() = 0;

    // Add an element to be drawn and updated in update function
    virtual void addElement(std::shared_ptr<Element_I> element) = 0;

    // Add an image to be drawn and update in update function
    virtual void addImage(std::shared_ptr<Image_I> iamge) = 0;

    // Create and return a tilemap, used as background
    virtual std::shared_ptr<TileMap_I> createTileMap(const char *imagePath) = 0;

    // Create a text and return the object
    virtual std::shared_ptr<Text_I> createText(const char *fontPath,
                                               uint8_t fontSize) = 0;

    // Returns the window width
    virtual std::shared_ptr<uint32_t> getWindowWidth() const = 0;

    // Returns the window height
    virtual std::shared_ptr<uint32_t> getWindowHeight() const = 0;

    // Callback for window resize event
    virtual void setResizeEventCallback(
        std::function<void(uint32_t width, uint32_t height)> callback) = 0;
};

#endif // GRAPHICS_INTERFACE_GRAPHICS_HPP