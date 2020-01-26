#ifndef GRAPHICS_INTERFACE_ELEMENT_HPP
#define GRAPHICS_INTERFACE_ELEMENT_HPP

#include <memory>
#include <vector>

#include "Image_I.hpp"

/**
 * A graphics element to hold one or several images. 
 * Images can be shifted for animation. 
 */
class Element_I
{
public:
    virtual ~Element_I() {}

    // Get all images such that these can be loaded on startup
    virtual std::vector<std::shared_ptr<Image_I>> getAllImages() = 0;

    // Get the current image index
    virtual uint getCurrentIndex() = 0;

    // If the window resizes, reposition image to new width/height
    // virtual void resizeEvent(uint32_t windowWidth, uint32_t windowHeight) = 0;
};

#endif // GRAPHICS_INTERFACE_ELEMENT_HPP
