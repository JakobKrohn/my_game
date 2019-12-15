#include "Movable/Movable.hpp"

#include <math.h>

#include "Logger/Logger.hpp"

using namespace components;

// Movable::Movable(uint32_t posX, uint32_t posY, uint16_t angle)
// {
//     m_position = std::make_shared<position_T>();
//     m_position->posX = posX;
//     m_position->posY = posY;
//     m_position->angle = angle;
// }

// Movable::Movable(position_T position)
// {
//     m_position = std::make_shared<position_T>();
//     m_position->posX = position.posX;
//     m_position->posY = position.posY;
//     m_position->angle = position.angle;
// }

Movable::Movable(graphics::Drawable_T data) : graphics::Drawable(data)
{

}

void Movable::setPosition(uint32_t x, uint32_t y, uint16_t angle)
{
    m_data.position.x = x;
    m_data.position.y = y;
    m_data.position.angle = angle;
    // m_position->posX = x;
    // m_position->posY = y;
    // m_position->angle = angle;
}

void Movable::moveForward(int velocity)
{
    print("Moving forward");
    // m_position->posX += sin(m_position->angle * M_PI / 180) * velocity;
    // m_position->posY -= cos(m_position->angle * M_PI / 180) * velocity;
    m_data.position.x += sin(m_data.position.angle * M_PI / 180) * velocity;
    m_data.position.y -= cos(m_data.position.angle * M_PI / 180) * velocity;
}

void Movable::moveBackward(int velocity)
{
    print("Moving backward");
    // m_position->posX -= sin(m_position->angle * M_PI / 180) * velocity;
    // m_position->posY += cos(m_position->angle * M_PI / 180) * velocity;
    m_data.position.x -= sin(m_data.position.angle * M_PI / 180) * velocity;
    m_data.position.y += cos(m_data.position.angle * M_PI / 180) * velocity;
}

void Movable::rotateRight(int velocity)
{
    print("Rotate right");
    updateAngle(velocity);
}

void Movable::rotateLeft(int velocity)
{
    print("Rotate left");
    updateAngle(-velocity);
}

const std::shared_ptr<position_T> Movable::getPosition() const
{
    return m_position;
}

void Movable::updateAngle(int angle)
{
    // m_position->angle += angle;
    // if (m_position->angle > 359)
    // {
    //     m_position->angle -= 360;
    // }
    // else if (m_position->angle < 0)
    // {
    //     m_position->angle += 360;
    // }
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