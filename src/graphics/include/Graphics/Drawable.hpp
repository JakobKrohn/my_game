#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <string>

#include "Drawable_I.hpp"

namespace graphics
{

class Drawable : public Drawable_I
{
public:
    Drawable(Drawable_T data);

    const std::string getImagePath() const;
    uint16_t getWidth() const;
    uint16_t getHeight() const;
    uint32_t getPosX() const;
    uint32_t getPosY() const;
    uint16_t getAngle() const;

protected:
    Drawable_T m_data;

private:
};

} // namespace graphics

#endif // DRAWABLE_HPP