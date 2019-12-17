#include "Movable/Movable.hpp"

#include <math.h>

#include "Logger/Logger.hpp"

using namespace components;

Movable::Movable(graphics::Drawable_T data) : graphics::Drawable(data)
{

}

void Movable::setPosition(uint32_t x, uint32_t y, uint16_t angle)
{
    m_data.position.x = x;
    m_data.position.y = y;
    m_data.position.angle = angle;
}

void Movable::moveForward(int velocity)
{
    m_data.position.x += sin(m_data.position.angle * M_PI / 180.0) * velocity;
    m_data.position.y -= cos(m_data.position.angle * M_PI / 180.0) * velocity;
}

void Movable::moveBackward(int velocity)
{
    m_data.position.x -= sin(m_data.position.angle * M_PI / 180) * velocity;
    m_data.position.y += cos(m_data.position.angle * M_PI / 180) * velocity;
}

void Movable::rotateRight(int velocity)
{
    updateAngle(velocity);
}

void Movable::rotateLeft(int velocity)
{
    updateAngle(-velocity);
}

const std::shared_ptr<position_T> Movable::getPosition() const
{
    return m_position;
}

void Movable::updateAngle(int angle)
{
    m_data.position.angle += angle;
    if (m_data.position.angle > 359)
    {
        m_data.position.angle -= 360;
    }
    else if (m_data.position.angle < 0)
    {
        m_data.position.angle += 360;
    }
}