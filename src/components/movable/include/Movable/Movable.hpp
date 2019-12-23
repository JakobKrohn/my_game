#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Movable_I.hpp"

#include <memory>
#include <vector>

#include "Graphics/Drawable.hpp"

namespace components
{

struct position_T
{
    float posX;
    float posY;
    float angle;
};

// class Movable : public graphics::Drawable
class Movable : public graphics::Drawable
{
public:
    Movable(graphics::Image_T data);
    Movable(std::vector<graphics::Image_T> imageData);

    void setPosition(uint32_t x, uint32_t y, uint16_t angle);

    void moveForward(int velocity);
    void moveBackward(int velocity);
    void rotateLeft(int velocity);
    void rotateRight(int velocity);

protected:
private:
    std::shared_ptr<position_T> m_position;

    void updateAngle(int angle);
};
} // namespace components

#endif // MOVABLE_HPP