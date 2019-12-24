#ifndef SDL_GRAPHICS_INTERFACE_HPP
#define SDL_GRAPHICS_INTERFACE_HPP

#include <memory>
#include <string>

#include "SdlImage_I.hpp"
#include "SdlElement_I.hpp"

namespace sdl_graphics
{

class Graphics_I
{
public:
    virtual void update() = 0;
    virtual void addElement(std::shared_ptr<SdlImage_I> element) = 0;
    virtual void addElement(std::shared_ptr<SdlElement_I> element) = 0;
};

} // namespace graphics

#endif // SDL_GRAPHICS_INTERFACE_HPP