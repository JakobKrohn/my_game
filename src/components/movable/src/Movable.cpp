#include "Movable/Movable.hpp"

#include <math.h>
#include <chrono>

#include "Logger/Logger.hpp"

using namespace components;

Movable::Movable(std::shared_ptr<Position_T> position, std::shared_ptr<Sprite_I> sprite)
    : m_position(position), m_sprite(sprite)
{
    print("Movable [", this, "] created");
}

Movable::~Movable()
{
    print("Movable [", this, "] destroyed");
}

void Movable::setBoundaries(Rectangle_T boundaries)
{
    m_boundaries = boundaries;
}

void Movable::setPosition(uint32_t x, uint32_t y, uint16_t angle)
{
    *m_position->x = x;
    *m_position->y = y;
    *m_position->angle = angle;
}

// TODO: Sprite should not decide this
bool Movable::isMoving() const
{
    return m_sprite->getState() != sprite_state::MOVING ? false : true;
}

const std::shared_ptr<Position_T> Movable::getPosition() const
{
    return m_position;
}

void Movable::moveForward(int velocity)
{
    m_sprite->setState(sprite_state::MOVING);
    auto x = *m_position->x + sin(*m_position->angle * M_PI / 180.0) * velocity;
    auto y = *m_position->y - cos(*m_position->angle * M_PI / 180.0) * velocity;
    if (isInsideBoundaries(x, y))
    {
        *m_position->x = x;
        *m_position->y = y;
    }
    // *m_position->x += sin(*m_position->angle * M_PI / 180.0) * velocity;
    // *m_position->y -= cos(*m_position->angle * M_PI / 180.0) * velocity;
}

void Movable::moveBackward(int velocity)
{
    m_sprite->setState(sprite_state::MOVING);
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

bool Movable::isInsideBoundaries(int x, int y) const
{
    if (x < (int)m_boundaries.minHorizontal)
        return false;
    if (x > (int)m_boundaries.maxHorizantal)
        return false;
    if (y < (int)m_boundaries.minVertical)
        return false;
    if (y > (int)m_boundaries.maxVertical)
        return false;
    return true;
}
