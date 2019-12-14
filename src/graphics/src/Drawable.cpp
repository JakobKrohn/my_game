#include "Graphics/Drawable.hpp"

using namespace graphics;

Drawable::Drawable(std::string imagePath, uint16_t width, uint16_t height, uint32_t posX, uint32_t posY, uint16_t angle) : m_imagePath(imagePath), m_width(width), m_height(height), m_positionX(posX), m_positionY(posY), m_angle(angle)
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

void Drawable::setPosX(uint32_t position)
{
    m_positionX = position;
}

void Drawable::setPosY(uint32_t position)
{
    m_positionY = position;
}

void Drawable::setAngle(uint16_t angle)
{
    m_angle = angle;
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

uint32_t Drawable::getPosX() const
{
    return m_positionX;
}

uint32_t Drawable::getPosY() const
{
    return m_positionY;
}

uint16_t Drawable::getAngle() const
{
    return m_angle;
}