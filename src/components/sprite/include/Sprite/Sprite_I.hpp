#ifndef COMPONENTS_SPRITE_INTERFACE_HPP
#define COMPONENTS_SPRITE_INTERFACE_HPP

namespace components
{

enum class sprite_state
{
    MOVING,
    STILL,
};

class Sprite_I
{
  public:
    virtual void setState(sprite_state state) = 0;
    virtual sprite_state getState() const = 0;
};

} // namespace components

#endif // COMPONENTS_SPRITE_INTERFACE_HPP