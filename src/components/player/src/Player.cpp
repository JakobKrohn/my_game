#include "Player/Player.hpp"

#include <iostream>

using namespace components;

Player::Player(std::string name, std::shared_ptr<Movable> movable, std::shared_ptr<Sprite> sprite) : m_name(name)
{
    m_movable = movable;
    m_sprite = sprite;
}

Player::~Player()
{
    print("Player destroyed");
}

std::shared_ptr<Movable> Player::getMovable() const
{
    return m_movable;
}

std::shared_ptr<Sprite> Player::getSprite() const
{
    return m_sprite;
}