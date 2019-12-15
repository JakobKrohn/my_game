#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <string>

#include "Drawable_I.hpp"

namespace graphics
{

class Drawable : public Drawable_I
{
public:
    Drawable(std::string imagePath, uint16_t width, uint16_t height, uint32_t posX, uint32_t posY, uint16_t angle);
    Drawable(Drawable_T data);

    // void setWidth(uint16_t width);
    // void setHeight(uint16_t height);
    // void setPosX(uint32_t position);
    // void setPosY(uint32_t position);
    // void setAngle(uint16_t angle);

    const std::string getImagePath() const;
    uint16_t getWidth() const;
    uint16_t getHeight() const;
    uint32_t getPosX() const;
    uint32_t getPosY() const;
    uint16_t getAngle() const;

protected:
    Drawable_T m_data;

private:
    const std::string m_imagePath;
    uint16_t m_width;
    uint16_t m_height;
    uint32_t m_positionX;
    uint32_t m_positionY;
    uint16_t m_angle;
};

} // namespace graphics

#endif // DRAWABLE_HPP