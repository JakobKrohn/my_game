#include "Player/Player.hpp"

#include <iostream>

using namespace components;

Player::Player(const char *name, graphics::Image_T drawData) : components::Movable(drawData), m_name(name)
{
}

Player::Player(const char *name, std::vector<graphics::Image_T> imageData) : components::Movable(imageData), m_name(name)
{
}