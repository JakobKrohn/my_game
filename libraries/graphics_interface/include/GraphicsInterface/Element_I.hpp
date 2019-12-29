#ifndef LIBRARY_ELEMENT_INTERFACE_HPP
#define LIBRARY_ELEMENT_INTERFACE_HPP

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

    // Get the current image
    virtual std::shared_ptr<Image_I> getCurrentImage() = 0;

    // Get the current image index
    virtual uint getCurrentIndex() = 0;
};

#endif // LIBRARY_ELEMENT_INTERFACE_HPP
