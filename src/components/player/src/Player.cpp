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

bool Player::isMoving()
{
    return sprite_state::STILL != m_sprite->getState();
}

void Player::moveForward(int velocity)
{
    m_sprite->setState(sprite_state::MOVING);
    m_movable->moveForward(velocity);
}

void Player::moveBackward(int velocity)
{
    // TODO: Create a print with timer!
    /** 
     * The timer should print the first its called, 
     * thereafter it should wait for the timer to go out
     * before printing again. 
     */
    print_limitimed("not implemented");
    // m_sprite->setState(sprite_state::MOVING);
    // m_movable->moveBackward(velocity);
}

void Player::rotateLeft(int velocity)
{
    m_sprite->setState(sprite_state::MOVING);
    m_movable->rotateLeft(velocity);
}

void Player::rotateRight(int velocity)
{
    m_sprite->setState(sprite_state::MOVING);
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