#include "Graphics/Drawable.hpp"

using namespace graphics;

Drawable::Drawable(std::string imagePath, uint16_t width, uint16_t height) : m_imagePath(imagePath), m_width(width), m_height(height)
{
}

void Drawable::setWidth(uint16_t width)
{
    m_width = width;
}

void Drawable::setHeight(uint16_t height)
{
    m_height = height;
}

const std::string Drawable::getImagePath() const
{
    return m_imagePath;
}

uint16_t Drawable::getWidth() const
{
    return m_width;
}

uint16_t Drawable::getHeight() const
{
    return m_height;
}
