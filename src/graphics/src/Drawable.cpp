#include "Graphics/Drawable.hpp"

using namespace graphics;

Drawable::Drawable(Image_T data) : m_data(data)
{
    
}

Drawable::Drawable(std::vector<Image_T> imageData) : m_imageData(imageData)
{

}

const std::string Drawable::getImagePath() const
{
    return m_data.imagePath;
}

uint16_t Drawable::getWidth() const
{
    return m_data.width;
}

uint16_t Drawable::getHeight() const
{
    return m_data.height;
}

uint32_t Drawable::getPosX() const
{
    return m_data.position.x;
}

uint32_t Drawable::getPosY() const
{
    return m_data.position.y;
}

uint16_t Drawable::getAngle() const
{
    return m_data.position.angle;
}