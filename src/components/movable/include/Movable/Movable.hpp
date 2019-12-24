#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Movable_I.hpp"

#include <memory>
#include <vector>

#include "Graphics/Drawable.hpp"
#include "SdlGraphics/SdlElement_I.hpp"


namespace components
{

struct position_T
{
    float x;
    float y;
    float angle;
};

class Movable : public sdl_graphics::SdlElement_I
{
public:
    Movable(graphics::Image_T image);
    Movable(std::vector<graphics::Image_T> imageData);

    void setPosition(uint32_t x, uint32_t y, uint16_t angle);

    void moveForward(int velocity);
    void moveBackward(int velocity);
    void rotateLeft(int velocity);
    void rotateRight(int velocity);

    // Sdl Element
    std::vector<std::shared_ptr<sdl_graphics::SdlImage_I>> getImages();
    const std::shared_ptr<sdl_graphics::SdlImage_I> getCurrentImage() const;

protected:
    // std::array<std::shared_ptr<graphics::Drawable>, 3> m_data;
    // std::shared_ptr<std::vector<graphics::Drawable>> m_drawData;
    std::vector<std::shared_ptr<graphics::Drawable>> m_drawData;
    // std::shared_ptr<std::vector<std::shared_ptr<graphics::Drawable>>> m_drawData;
    // std::vector<graphics::Drawable> m_drawData;

private:
    std::shared_ptr<position_T> m_position;

    void updateAngle(int angle);
};
} // namespace components

#endif // MOVABLE_HPP