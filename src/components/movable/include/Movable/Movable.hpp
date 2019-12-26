#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Movable_I.hpp"

#include <memory>
#include <vector>

#include "Drawable/Drawable.hpp"
#include "GraphicsInterface/Element_I.hpp"

namespace components
{

struct Position_T
{
    std::shared_ptr<float> x;
    std::shared_ptr<float> y;
    std::shared_ptr<float> angle;
};

class Movable : public Element_I
{
public:

    Movable(std::shared_ptr<Position_T> position, std::vector<std::shared_ptr<Drawable>>);
    
    // Element_I 
    std::vector<std::shared_ptr<Image_I>> getAllImages();
    std::shared_ptr<Image_I> getCurrentImage();
    uint getCurrentIndex();

    void setPosition(uint32_t x, uint32_t y, uint16_t angle);

    void moveForward(int velocity);
    void moveBackward(int velocity);
    void rotateLeft(int velocity);
    void rotateRight(int velocity);

protected:
private:
    std::shared_ptr<Position_T> m_position;

    void updateAngle(int angle);
};
} // namespace components

#endif // MOVABLE_HPP