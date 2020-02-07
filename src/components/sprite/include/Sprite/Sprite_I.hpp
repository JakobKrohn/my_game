#ifndef COMPONENTS_SPRITE_INTERFACE_HPP
#define COMPONENTS_SPRITE_INTERFACE_HPP

namespace components
{

enum class sprite_state : int
{
    IDLE = 0,
    ATTACK,
    MOVING,
    RELOAD,
    FIRING, 
    _END
};

class Sprite_I
{
public:
    virtual void setState(sprite_state state) = 0;
    virtual sprite_state getState() const = 0;

    virtual void setIdleAssets(std::vector<const char *> &&assets) = 0;
    virtual void setAttackAssets(std::vector<const char *> &&assets) = 0;
    virtual void setMovingAssets(std::vector<const char *> &&assets) = 0;
    virtual void setReloadAssets(std::vector<const char *> &&assets) = 0;
    virtual void setFiringAssets(std::vector<const char *> &&assets) = 0;
};

} // namespace components

#endif // COMPONENTS_SPRITE_INTERFACE_HPP