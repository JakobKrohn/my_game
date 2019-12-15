#include "Graphics/Drawable.hpp"

using namespace graphics;

Drawable::Drawable(std::string imagePath, uint16_t width, uint16_t height, uint32_t posX, uint32_t posY, uint16_t angle) : m_imagePath(imagePath), m_width(width), m_height(height), m_positionX(posX), m_positionY(posY), m_angle(angle)
{
}

Drawable::Drawable(Drawable_T data) : m_data(data)
{
    
}

void Drawable::setWidth(uint16_t width)
{
    // m_width = width;
    m_data.width = width;
}

void Drawable::setHeight(uint16_t height)
{
    // m_height = height;
    m_data.height = height;
}

void Drawable::setPosX(uint32_t position)
{
    // m_positionX = position;
    m_data.posX = position;
}

void Drawable::setPosY(uint32_t position)
{
    // m_positionY = position;
    m_data.posY = position;
}

void Drawable::setAngle(uint16_t angle)
{
    // m_angle = angle;
    m_data.angle = angle;
}

const std::string Drawable::getImagePath() const
{
    // return m_imagePath;
    return m_data.imagePath;
}

uint16_t Drawable::getWidth() const
{
    // return m_width;
    return m_data.width;
}

uint16_t Drawable::getHeight() const
{
    // return m_height;
    return m_data.height;
}

uint32_t Drawable::getPosX() const
{
    // return m_positionX;
    return m_data.posX;
}

uint32_t Drawable::getPosY() const
{
    // return m_positionY;
    return m_data.posY;
}

uint16_t Drawable::getAngle() const
{
    // return m_angle;
    return m_data.angle;
}