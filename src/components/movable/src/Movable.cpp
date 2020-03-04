#include "Movable/Movable.hpp"

#include <chrono>
#include <math.h>

#include "Logger/Logger.hpp"

using namespace components;

Movable::Movable()
{
    m_position = std::make_shared<components::Position_T>();
    m_position->x = std::make_shared<float>(250);
    m_position->y = std::make_shared<float>(250);
    m_position->angle = std::make_shared<float>(0);
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

const std::shared_ptr<Position_T> Movable::getPosition() const
{
    return m_position;
}

void Movable::move(int velocity)
{
    auto x = *m_position->x + sin(*m_position->angle * M_PI / 180.0) * velocity;
    auto y = *m_position->y - cos(*m_position->angle * M_PI / 180.0) * velocity;
    if (isInsideBoundaries(x, y))
    {
        *m_position->x = x;
        *m_position->y = y;
    }
}

void Movable::rotate(int velocity)
{
    updateAngle(velocity);
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
