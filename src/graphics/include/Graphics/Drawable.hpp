#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <string>

namespace graphics
{

class Drawable
{
public:
    Drawable(std::string imagePath, uint16_t width, uint16_t height);

    void setWidth(uint16_t width);
    void setHeight(uint16_t height);

    const std::string getImagePath() const;
    uint16_t getWidth() const;
    uint16_t getHeight() const;

private:
    const std::string m_imagePath;
    uint16_t m_width;
    uint16_t m_height;
};

} // namespace graphics

#endif // DRAWABLE_HPP