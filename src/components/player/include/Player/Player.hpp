#ifndef COMPONENTS_PLAYER_HPP
#define COMPONENTS_PLAYER_HPP

#include "Player_I.hpp"

#include <vector>

#include "Movable/Movable_I.hpp"
#include "Movable/Movable.hpp"
#include "Sprite/Sprite.hpp"

namespace components
{

class Player
{
public:
    explicit Player(std::string name, std::shared_ptr<Movable> movable, std::shared_ptr<Sprite> sprite);
    Player() = delete;
    ~Player();

    std::shared_ptr<Movable> getMovable() const;
    std::shared_ptr<Sprite> getSprite() const;

private:
    const std::string m_name;
    std::shared_ptr<Movable> m_movable;
    std::shared_ptr<Sprite> m_sprite;
};

} // namespace components

#endif // COMPONENTS_PLAYER_HPP