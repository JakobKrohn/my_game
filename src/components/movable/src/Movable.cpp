#include "Movable/Movable.hpp"

#include <math.h>

#include "Logger/Logger.hpp"

using namespace components;

Movable::Movable(graphics::Image_T image) //: graphics::Drawable(image)
{
    m_position = std::make_shared<position_T>();
    // m_position->x = new int(0);
    m_position->x = new float(0);
    m_position->y = new float(0);
    m_position->angle = new float(0);
    // image.position.x = m_position->x;
    image.position.x = m_position->x;
    image.position.y = m_position->y;
    image.position.angle = m_position->angle;
    // setPosition(500, 500, 0);
    // m_drawData.push_back(graphics::Drawable(image));
    m_drawData.emplace_back(std::make_shared<graphics::Drawable>(graphics::Drawable(image)));
}

Movable::Movable(std::vector<graphics::Image_T> imageData) //: graphics::Drawable(imageData[0])
{
    m_position = std::make_shared<position_T>();
    // m_position->x = new int(0);
    m_position->x = new float(250);
    m_position->y = new float(250);
    m_position->angle = new float(0);

    for (auto &image : imageData)
    {
        // set position
        // image.position.x = m_position->x;
        image.position.x = m_position->x;
        image.position.y = m_position->y;
        image.position.angle = m_position->angle;
        m_drawData.emplace_back(std::make_shared<graphics::Drawable>(graphics::Drawable(image)));
    }
}

void Movable::setPosition(uint32_t x, uint32_t y, uint16_t angle)
{
    *m_position->x = x;
    *m_position->y = y;
    *m_position->angle = angle;
}

std::vector<std::shared_ptr<sdl_graphics::SdlImage_I>> Movable::getImages()
{
    // TODO: fix this.
    std::vector<std::shared_ptr<sdl_graphics::SdlImage_I>> vec(m_drawData.begin(), m_drawData.end());
    return vec;
}

const std::shared_ptr<sdl_graphics::SdlImage_I> Movable::getCurrentImage() const
{
    static auto index = 0;
    index++;
    if (index == m_drawData.size()) 
        index = 0;
    return m_drawData[index];
}

void Movable::moveForward(int velocity)
{
    *m_position->x += sin(*m_position->angle * M_PI / 180.0) * velocity;
    *m_position->y -= cos(*m_position->angle * M_PI / 180.0) * velocity;
}

void Movable::moveBackward(int velocity)
{
    *m_position->x -= sin(*m_position->angle * M_PI / 180) * velocity;
    *m_position->y += cos(*m_position->angle * M_PI / 180) * velocity;
}

void Movable::rotateRight(int velocity)
{
    updateAngle(velocity);
}

void Movable::rotateLeft(int velocity)
{
    updateAngle(-velocity);
}

void Movable::updateAngle(int angle)
{
    *m_position->angle += angle;
    if (*m_position->angle > 359)
    {
        *m_position->angle -= 360;
    }
    else if (*m_position->angle < 0)
    {
        *m_position->angle += 360;
    }
}