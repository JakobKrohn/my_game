#include "Movable/Movable.hpp"

#include <math.h>
#include <chrono>

#include "Logger/Logger.hpp"

using namespace components;

Movable::Movable(std::shared_ptr<Position_T> position, std::shared_ptr<Sprite_I> sprite) : m_sprite(sprite)
{
    m_position = position;
}

void Movable::setPosition(uint32_t x, uint32_t y, uint16_t angle)
{
    *m_position->x = x;
    *m_position->y = y;
    *m_position->angle = angle;
}

void Movable::moveForward(int velocity)
{
    *m_position->x += sin(*m_position->angle * M_PI / 180.0) * velocity;
    *m_position->y -= cos(*m_position->angle * M_PI / 180.0) * velocity;
    m_sprite->setState(sprite_state::MOVING);
}

void Movable::moveBackward(int velocity)
{
    *m_position->x -= sin(*m_position->angle * M_PI / 180) * velocity;
    *m_position->y += cos(*m_position->angle * M_PI / 180) * velocity;
    m_sprite->setState(sprite_state::MOVING);
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