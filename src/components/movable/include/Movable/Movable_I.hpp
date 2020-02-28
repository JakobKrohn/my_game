#ifndef MOVABLE_INTERFACE_HPP
#define MOVABLE_INTERFACE_HPP

#include <memory>

namespace components
{

struct Position_T
{
    std::shared_ptr<float> x;
    std::shared_ptr<float> y;
    std::shared_ptr<float> angle;
};

struct Rectangle_T
{
    unsigned int minHorizontal;
    unsigned int minVertical;
    unsigned int maxHorizantal;
    unsigned int maxVertical;
};

class Movable_I
{
  public:
    virtual ~Movable_I()
    {
    }
    // Set movement boundaries
    // minHorizontal(x), minVertical(y), maxHorizontal(x), maxVertical(y)
    virtual void setBoundaries(Rectangle_T boundaries) = 0;
    virtual void setPosition(uint32_t x, uint32_t y, uint16_t angle) = 0;
    virtual const std::shared_ptr<Position_T> getPosition() const = 0;
    // Move the x,y position 
    virtual void move(int velocity) = 0;
    // Rotate angle
    virtual void rotate(int velocity) = 0;
};

} // namespace components

#endif // MOVABLE_INTERFACE_HPP