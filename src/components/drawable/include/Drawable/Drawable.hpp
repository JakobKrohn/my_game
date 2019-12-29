#ifndef COMPONENT_DRAWABLE_HPP
#define COMPONENT_DRAWABLE_HPP

#include "GraphicsInterface/Image_I.hpp"

namespace components
{

struct Drawable_T
{
    std::string imagePath; // TODO: const
    std::shared_ptr<uint32_t> width;
    std::shared_ptr<uint32_t> height;
    std::shared_ptr<float> posX;  // TODO: uin32_T
    std::shared_ptr<float> posY;  // TODO: uin32_T
    std::shared_ptr<float> angle; // TODO: uint16_T
};

class Drawable : public Image_I
{
public:
    explicit Drawable(std::unique_ptr<Drawable_T> data);

    // Image_I
    const std::string getImagePath() const;
    uint32_t getWidth() const;
    uint32_t getHeight() const;
    uint32_t getPosX() const;
    uint32_t getPosY() const;
    uint16_t getAngle() const;

private:
    std::unique_ptr<Drawable_T> m_data;
};

} // namespace components

#endif // COMPONENT_DRAWABLE_HPP