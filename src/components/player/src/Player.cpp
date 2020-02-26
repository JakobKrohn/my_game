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

void Player::moveForward(int velocity)
{
    m_movable->moveForward(velocity);
}

void Player::moveBackward(int velocity)
{
    m_movable->moveBackward(velocity);
}

void Player::rotateLeft(int velocity)
{
    m_movable->rotateLeft(velocity);
}

void Player::rotateRight(int velocity)
{
    m_movable->rotateRight(velocity);
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