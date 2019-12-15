#include "Player/Player.hpp"

#include <iostream>

using namespace components;

Player::Player(const char *name, graphics::Drawable_T drawData) : components::Movable(drawData), name_(name)
{
}

void Player::initialize()
{
}

void Player::getData()
{
}