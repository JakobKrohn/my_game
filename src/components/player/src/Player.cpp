#include "Player/Player.hpp"

#include <iostream>

using namespace components;

Player::Player(const char *name, position_T position, graphics::Drawable_T drawData) : components::Movable(position), graphics::Drawable(drawData), name_(name)
{
}

void Player::initialize()
{
}

void Player::getData()
{
}