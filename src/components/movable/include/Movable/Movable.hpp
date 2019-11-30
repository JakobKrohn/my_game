#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Movable_I.hpp"

#include <memory>

struct position_t
{
    int x;
    int y;
    int angle;
};

namespace component
{
class Movable
{
public:
    Movable();

    void setPosition(int x, int y, int angle);

    void moveForward(int velocity);
    void moveBackward(int velocity);
    void rotateLeft(int velocity);
    void rotateRight(int velocity);

    const std::shared_ptr<position_t> getPosition() const;

protected:
private:
    std::shared_ptr<position_t> current_;

    void updateAngle(int angle);
};
} // namespace component

#endif // MOVABLE_HPP