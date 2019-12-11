#ifndef GRAPHICS_INTERFACE_HPP
#define GRAPHICS_INTERFACE_HPP

#include <memory>

#include "Drawable_I.hpp"

namespace graphics
{
    class Graphics_I
    {
        virtual void createWindow(unsigned int windowPositionX = 0, unsigned int windowPositionY = 0) = 0;
        virtual void update() = 0;
        virtual void addElement(std::shared_ptr<Drawable_I> element) = 0;
    };
} // namespace graphics


#endif // GRAPHICS_INTERFACE_HPP