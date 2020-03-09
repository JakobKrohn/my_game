#include "Player/Player.hpp"

#include <iostream>

#include "Logger/Logger.hpp"

using namespace components;

Player::Player(std::string name, std::shared_ptr<Movable_I> movable,
               std::shared_ptr<Sprite_I> sprite)
    : m_name(name), m_movable(movable), m_sprite(sprite), m_isMoving(false)
{
    m_moveTime = std::chrono::system_clock::now();
    auto position = m_movable->getPosition();

    m_sprite->setAngleOffset(270);
    m_sprite->setPosition(position->x, position->y, position->angle);
    // clang-format off
    std::vector<const char *> gunIdle = 
    {
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_0.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_1.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_2.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_3.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_4.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_5.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_6.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_7.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_8.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_9.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_10.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_11.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_12.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_13.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_14.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_15.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_16.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_17.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_18.png",
        "assets/Top_Down_Survivor/handgun/idle/survivor-idle_handgun_19.png",
    };
    std::vector<const char *> gunMove = 
    {
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_0.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_1.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_2.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_3.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_4.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_5.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_6.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_7.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_8.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_9.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_10.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_11.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_12.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_13.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_14.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_15.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_16.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_17.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_18.png",
        "assets/Top_Down_Survivor/handgun/move/survivor-move_handgun_19.png",
    };
    std::vector<const char *> gunShoot = 
    {
        "assets/Top_Down_Survivor/handgun/shoot/survivor-shoot_handgun_0.png",
        "assets/Top_Down_Survivor/handgun/shoot/survivor-shoot_handgun_1.png",
        "assets/Top_Down_Survivor/handgun/shoot/survivor-shoot_handgun_2.png",
    };
    // clang-format on
    m_sprite->setSizePercentage(1);

    m_idleSequence = m_sprite->addSequence(gunIdle);
    m_movingSequence = m_sprite->addSequence(gunMove);
    m_shootSequence = m_sprite->addSequence(gunShoot, true);

    m_sprite->setCurrentSequence(m_idleSequence);

    m_sprite->setTimeInterval(80, m_idleSequence);
    m_sprite->setTimeInterval(1, m_movingSequence);
    m_sprite->setTimeInterval(50, m_shootSequence);
}

Player::~Player()
{
    print("Player destroyed");
}

void Player::update()
{
    if (!m_isMoving)
        return;
    using namespace std::chrono;

    std::chrono::duration<double> move_time = system_clock::now() - m_moveTime;

    if (move_time.count() > 0.05)
    {
        m_isMoving = false;
        m_sprite->setCurrentSequence(m_idleSequence);
        std::cout << "reset\n";
    }
}

bool Player::isMoving() const
{
    return m_isMoving;
}

void Player::shoot()
{
    // std::cout << "shoot\n";
    m_sprite->setCurrentSequence(m_shootSequence);
}

void Player::moveForward(int velocity)
{
    m_moveTime = std::chrono::system_clock::now();
    m_isMoving = true;
    m_sprite->setCurrentSequence(m_movingSequence);
    m_movable->move(velocity);
}

void Player::moveBackward(int velocity)
{
    print_limitimed("not implemented");
    m_sprite->setCurrentSequence(m_idleSequence);
}

void Player::rotateLeft(int velocity)
{
    m_movable->rotate(-velocity);
}

void Player::rotateRight(int velocity)
{
    m_movable->rotate(velocity);
}

const char *Player::getName() const
{
    return m_name.c_str();
}

std::shared_ptr<Movable_I> Player::getMovable() const
{
    return m_movable;
}
