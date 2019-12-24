#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <string>
#include <vector>

#include "Drawable_I.hpp"
#include "SdlGraphics/SdlImage_I.hpp"

namespace graphics
{

// TODO: inherit from sdl_graphcis::SdlElement_I
class Drawable : public sdl_graphics::SdlImage_I
{
public:
    Drawable(Image_T data);
    Drawable(std::vector<Image_T> imageData);
    
    const std::string getImagePath() const;
    uint16_t getWidth() const;
    uint16_t getHeight() const;
    uint32_t getPosX() const;
    uint32_t getPosY() const;
    uint16_t getAngle() const;

protected:
    Image_T m_data;
    std::vector<Image_T> m_imageData;

private:
};

} // namespace graphics

#endif // DRAWABLE_HPP