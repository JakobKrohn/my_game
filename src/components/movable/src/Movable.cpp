#include "Movable/Movable.hpp"

#include <math.h>

using namespace components;

Movable::Movable(uint32_t posX, uint32_t posY, uint16_t angle)
{
    m_position = std::make_shared<position_T>();
    m_position->posX = posX;
    m_position->posY = posY;
    m_position->angle = angle;
}

Movable::Movable(position_T position)
{
    m_position = std::make_shared<position_T>();
    m_position->posX = position.posX;
    m_position->posY = position.posY;
    m_position->angle = position.angle;
}

void Movable::setPosition(uint32_t x, uint32_t y, uint16_t angle)
{
    m_position->posX = x;
    m_position->posY = y;
    m_position->angle = angle;
}

void Movable::moveForward(int velocity)
{
    m_position->posX += sin(m_position->angle * M_PI / 180) * velocity;
    m_position->posY -= cos(m_position->angle * M_PI / 180) * velocity;
}

void Movable::moveBackward(int velocity)
{
    m_position->posX -= sin(m_position->angle * M_PI / 180) * velocity;
    m_position->posY += cos(m_position->angle * M_PI / 180) * velocity;
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
    m_position->angle += angle;
    if (m_position->angle > 359)
    {
        m_position->angle -= 360;
    }
    else if (m_position->angle < 0)
    {
        m_position->angle += 360;
    }
}