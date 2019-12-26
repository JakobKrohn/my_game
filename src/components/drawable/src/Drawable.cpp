#include "Drawable/Drawable.hpp"

using namespace components;

Drawable::Drawable(std::unique_ptr<Drawable_T> data)
{
    m_data = std::move(data);
}

const std::string Drawable::getImagePath() const
{
    return m_data->imagePath;
}

uint32_t Drawable::getWidth() const
{
    return *m_data->width;
}

uint32_t Drawable::getHeight() const
{
    return *m_data->height;
}

uint32_t Drawable::getPosX() const
{
    return static_cast<uint32_t>(*m_data->posX);
}

uint32_t Drawable::getPosY() const
{
    return static_cast<uint32_t>(*m_data->posY);
}

uint16_t Drawable::getAngle() const
{
    return static_cast<uint32_t>(*m_data->angle);
}