#ifndef COMPONENTS_MOVABLE_HPP
#define COMPONENTS_MOVABLE_HPP

#include "Movable_I.hpp"

#include <memory>
#include <vector>

#include "Drawable/Drawable.hpp"
#include "Logger/Logger.hpp"
#include "Sprite/Sprite_I.hpp"

namespace components
{

struct Position_T
{
    std::shared_ptr<float> x;
    std::shared_ptr<float> y;
    std::shared_ptr<float> angle;
};

class Movable
{
public:
    explicit Movable(std::shared_ptr<Position_T> position, std::shared_ptr<Sprite_I> sprite);
    Movable(const Movable &) = delete;

    void setPosition(uint32_t x, uint32_t y, uint16_t angle);
    const std::shared_ptr<Position_T> getPosition() const;

    void moveForward(int velocity);
    void moveBackward(int velocity);
    void rotateLeft(int velocity);
    void rotateRight(int velocity);

protected:
private:
    std::shared_ptr<Position_T> m_position;
    std::shared_ptr<Sprite_I> m_sprite;

    void updateAngle(int angle);
};

} // namespace components

#endif // COMPONENTS_MOVABLE_HPP