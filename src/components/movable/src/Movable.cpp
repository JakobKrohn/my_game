#include "Movable/Movable.hpp"

#include <math.h>
#include <chrono>

#include "Logger/Logger.hpp"

using namespace components;

Movable::Movable(std::shared_ptr<Position_T> position, std::vector<std::shared_ptr<Drawable>> drawables) : m_drawables(drawables), m_isMoving(false)
{
    m_position = position;
}

std::vector<std::shared_ptr<Image_I>> Movable::getAllImages()
{
    // DO NOT CAST LIKE THIS!
    std::vector<std::shared_ptr<Image_I>> data;
    for (const auto &d : m_drawables)
    {
        data.push_back(d);
    }
    return data;
}

std::shared_ptr<Image_I> Movable::getCurrentImage()
{
}

uint Movable::getCurrentIndex()
{
    if (!m_isMoving)
    {
        return 0;
    }
    static bool test = 0;
    static auto t = std::chrono::high_resolution_clock::now();
    auto n = std::chrono::high_resolution_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(n - t).count() > 250)
    {
        t = std::chrono::high_resolution_clock::now();
        test = !test;
    }

    m_isMoving = false;

    return (test ? 1 : 2);
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
    m_isMoving = true;
}

void Movable::moveBackward(int velocity)
{
    *m_position->x -= sin(*m_position->angle * M_PI / 180) * velocity;
    *m_position->y += cos(*m_position->angle * M_PI / 180) * velocity;
    m_isMoving = true;
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