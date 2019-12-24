#ifndef SDL_ELEMENT_INTERFACE_HPP
#define SDL_ELEMENT_INTERFACE_HPP

#include <memory>
#include <vector>

#include "SdlImage_I.hpp"

namespace sdl_graphics
{

class SdlElement_I
{
public:
    // virtual const std::vector<SdlImage_I> getImages() const = 0;
    // virtual std::shared_ptr<std::vector<std::shared_ptr<sdl_graphics::SdlImage_I>>> getImages() = 0;
    virtual std::vector<std::shared_ptr<SdlImage_I>> getImages() = 0;
    // virtual std::shared_ptr<std::vector<SdlImage_I>> getImages() = 0;
    virtual const std::shared_ptr<SdlImage_I> getCurrentImage() const = 0;
    // virtual const SdlImage_I getCurrentImage() const = 0;

private:
};

} // namespace sdl_graphics

#endif // SDL_ELEMENT_INTERFACE_HPP