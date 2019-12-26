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

std::shared_ptr<uint32_t> Drawable::getWidth() const
{
    return m_data->width;
}

std::shared_ptr<uint32_t> Drawable::getHeight() const
{
    return m_data->height;
}

std::shared_ptr<uint32_t> Drawable::getPosX() const
{
    // return m_data->posX;
}

std::shared_ptr<uint32_t> Drawable::getPosY() const
{

}

std::shared_ptr<uint16_t> Drawable::getAngle() const
{

}