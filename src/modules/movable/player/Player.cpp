#include "Player.hpp"

#include <iostream>

#include "Output.hpp"
#include "Settings.hpp"

Player::Player(const char * name) : name_(name) {
    drawData->x = getPosition()->x;
    drawData->y = getPosition()->y;
    drawData->angle = getPosition()->angle;
    drawData->height = PLAYER_SIZE_HEIGHT;
    drawData->width = PLAYER_SIZE_WIDTH;
    print(name, " created");
}

const std::shared_ptr<const drawable_t> Player::getDrawable() const {
    return drawData;
}

void Player::initialize() {
}

void Player::getData() {
    print(name_, "\t", getPostitionString());
}