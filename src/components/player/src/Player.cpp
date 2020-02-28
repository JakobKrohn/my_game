#include "Player/Player.hpp"

#include <iostream>

#include "Logger/Logger.hpp"

using namespace components;

Player::Player(std::string name, std::shared_ptr<Movable_I> movable,
               std::shared_ptr<Sprite> sprite)
    : m_name(name)
{
    m_movable = movable;
    m_sprite = sprite;
}

Player::~Player()
{
    print("Player destroyed");
}

bool Player::isMoving() const
{
    return sprite_state::STILL != m_sprite->getState();
}

void Player::moveForward(int velocity)
{
    m_sprite->setState(sprite_state::MOVING);
    m_movable->move(velocity);
}

void Player::moveBackward(int velocity)
{
    print_limitimed("not implemented");
}

void Player::rotateLeft(int velocity)
{
    m_sprite->setState(sprite_state::MOVING);
    m_movable->rotate(-velocity);
}

void Player::rotateRight(int velocity)
{
    m_sprite->setState(sprite_state::MOVING);
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

std::shared_ptr<Sprite> Player::getSprite() const
{
    return m_sprite;
}