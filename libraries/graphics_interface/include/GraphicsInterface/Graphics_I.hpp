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
    virtual ~Graphics_I(){}

    // Render objects and update window
    virtual void update() = 0;

    // Add an element to be drawn and updated in update function
    virtual void addElement(std::shared_ptr<Element_I> element) = 0;
};

#endif // LIBRARY_GRAPHICS_INTERFACE_HPP