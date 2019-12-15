#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Movable_I.hpp"

#include <memory>

#include "Graphics/Drawable.hpp"

namespace components
{

struct position_T
{
    uint32_t posX;
    uint32_t posY;
    int angle;
};

class Movable : public graphics::Drawable
{
public:
    // Movable(uint32_t posX, uint32_t posY, uint16_t angle);
    // Movable(position_T position);
    Movable(graphics::Drawable_T data);

    void setPosition(uint32_t x, uint32_t y, uint16_t angle);

    void moveForward(int velocity);
    void moveBackward(int velocity);
    void rotateLeft(int velocity);
    void rotateRight(int velocity);

    const std::shared_ptr<position_T> getPosition() const;

protected:
private:
    std::shared_ptr<position_T> m_position;

    void updateAngle(int angle);
};
} // namespace components

#endif // MOVABLE_HPP