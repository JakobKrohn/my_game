#ifndef LIBRARY_GRAPHICS_INTERFACE_HPP
#define LIBRARY_GRAPHICS_INTERFACE_HPP

#include <memory>

#include "Element_I.hpp"

/**
 * Interface for graphics libraries
 */
class Graphics_I
{
public:
    virtual ~Graphics_I() {}

    // Render objects and update window
    virtual void update() = 0;

    // Add an element to be drawn and updated in update function
    virtual void addElement(std::shared_ptr<Element_I> element) = 0;

    // Add an image to be drawn and update in update function
    virtual void addImage(std::shared_ptr<Image_I> iamge) = 0;

    // Returns the window width
    virtual std::shared_ptr<uint32_t> getWindowWidth() const = 0;

    // Returns the window height
    virtual std::shared_ptr<uint32_t> getWindowHeight() const = 0;
};

#endif // LIBRARY_GRAPHICS_INTERFACE_HPP