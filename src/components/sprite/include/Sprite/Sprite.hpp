#ifndef COMPONENTS_SPRITE_HPP
#define COMPONENTS_SPRITE_HPP

#include "GraphicsInterface/Element_I.hpp"
#include "Drawable/Drawable.hpp"
#include "Sprite_I.hpp"

namespace components
{

class Sprite : public Element_I, public Sprite_I
{
public:
    explicit Sprite(std::vector<std::shared_ptr<Drawable>> drawables);
    ~Sprite();

    // Element_I
    std::vector<std::shared_ptr<Image_I>> getAllImages();
    uint getCurrentIndex();
    // void resizeEvent(uint32_t windowWidth, uint32_t windowHeight);

    // Sprite_I
    void setState(sprite_state state);
    sprite_state getState() const;

private:
    std::vector<std::shared_ptr<Drawable>> m_drawables;
    sprite_state m_state;
};

} // namespace components

#endif // COMPONENTS_SPRITE_HPP