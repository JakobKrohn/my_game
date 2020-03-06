#include "Player/Player.hpp"

#include <iostream>

#include "Logger/Logger.hpp"

using namespace components;

Player::Player(std::string name, std::shared_ptr<Movable_I> movable,
               std::shared_ptr<Sprite_I> sprite)
    : m_name(name), m_movable(movable), m_sprite(sprite)
{
    auto position = m_movable->getPosition();
    m_sprite->setPosition(position->x, position->y, position->angle);
    std::vector<const char *> still = {"assets/player_green_still.png", 
    "assets/player_green_left.png", "assets/player_green_right.png"};
    auto indexStill = m_sprite->addSequence(still);
    m_sprite->setTimeInterval(500);
}

Player::~Player()
{
    print("Player destroyed");
}

bool Player::isMoving() const
{
    return false;
    // return sprite_state::STILL != m_sprite->getState();
}

void Player::moveForward(int velocity)
{
    // m_sprite->setState(sprite_state::MOVING);
    // m_drawable->
    m_movable->move(velocity);
}

void Player::moveBackward(int velocity)
{
    print_limitimed("not implemented");
}

void Player::rotateLeft(int velocity)
{
    // m_sprite->setState(sprite_state::MOVING);
    m_movable->rotate(-velocity);
}

void Player::rotateRight(int velocity)
{
    // m_sprite->setState(sprite_state::MOVING);
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
