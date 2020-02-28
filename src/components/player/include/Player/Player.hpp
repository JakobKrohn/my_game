#ifndef COMPONENTS_PLAYER_HPP
#define COMPONENTS_PLAYER_HPP

#include "Player_I.hpp"

#include <vector>

#include "Movable/Movable_I.hpp"
#include "Sprite/Sprite.hpp"

namespace components
{

class Player
{
  public:
    explicit Player(std::string name, std::shared_ptr<Movable_I> movable,
                    std::shared_ptr<Sprite> sprite);
    Player() = delete;
    ~Player();

    bool isMoving() const;
    void moveForward(int velocity);
    void moveBackward(int velocity);
    void rotateLeft(int velocity);
    void rotateRight(int velocity);

    const char *getName() const;
    std::shared_ptr<Movable_I> getMovable() const;
    std::shared_ptr<Sprite> getSprite() const;

  private:
    const std::string m_name;
    std::shared_ptr<Movable_I> m_movable;
    std::shared_ptr<Sprite> m_sprite;
};

} // namespace components

#endif // COMPONENTS_PLAYER_HPP