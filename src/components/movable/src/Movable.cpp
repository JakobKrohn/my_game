#include "Movable/Movable.hpp"

#include <math.h>

#include "Logger/Logger.hpp"

using namespace components;

Movable::Movable(std::shared_ptr<Position_T> position, std::vector<std::shared_ptr<Drawable>>)
{
}

std::vector<std::shared_ptr<Image_I>> Movable::getAllImages()
{

}

std::shared_ptr<Image_I> Movable::getCurrentImage()
{

}

uint Movable::getCurrentIndex()
{

}

// Movable::Movable(graphics::Image_T data) : graphics::Drawable(data)
// {

// }

// Movable::Movable(std::vector<graphics::Image_T> imageData) : graphics::Drawable(imageData)
// {

// }

void Movable::setPosition(uint32_t x, uint32_t y, uint16_t angle)
{
    // m_data.position.x = x;
    // m_data.position.y = y;
    // m_data.position.angle = angle;
}

void Movable::moveForward(int velocity)
{
    // m_data.position.x += sin(m_data.position.angle * M_PI / 180.0) * velocity;
    // m_data.position.y -= cos(m_data.position.angle * M_PI / 180.0) * velocity;
}

void Movable::moveBackward(int velocity)
{
    // m_data.position.x -= sin(m_data.position.angle * M_PI / 180) * velocity;
    // m_data.position.y += cos(m_data.position.angle * M_PI / 180) * velocity;
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
    // m_data.position.angle += angle;
    // if (m_data.position.angle > 359)
    // {
    //     m_data.position.angle -= 360;
    // }
    // else if (m_data.position.angle < 0)
    // {
    //     m_data.position.angle += 360;
    // }
}