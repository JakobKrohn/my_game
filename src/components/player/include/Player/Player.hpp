#ifndef COMPONENTS_PLAYER_HPP
#define COMPONENTS_PLAYER_HPP

#include "Player_I.hpp"

#include <chrono>
#include <vector>

#include "GraphicsInterface/Sprite_I.hpp"
#include "Movable/Movable_I.hpp"

namespace components
{

class Player
{
  public:
    explicit Player(std::string name, std::shared_ptr<Movable_I> movable,
                    std::shared_ptr<Sprite_I> sprite);
    Player() = delete;
    ~Player();

    void update();

    bool isMoving() const;
    void moveForward(int velocity);
    void moveBackward(int velocity);
    void rotateLeft(int velocity);
    void rotateRight(int velocity);

    const char *getName() const;
    std::shared_ptr<Movable_I> getMovable() const;

  private:
    const std::string m_name;
    std::shared_ptr<Movable_I> m_movable;
    std::shared_ptr<Sprite_I> m_sprite;
    unsigned int m_idleSequence;
    unsigned int m_movingSequence;
    bool m_isMoving;
    std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration> m_moveTime;
};

} // namespace components

#endif // COMPONENTS_PLAYER_HPP