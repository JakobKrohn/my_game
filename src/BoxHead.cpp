#include "BoxHead.hpp"

#include "global/Output.hpp"
#include "Settings.hpp"
#include "interfaces/IDrawable.hpp"

BoxHead::BoxHead() {
    isRunning_ = false;
}

void BoxHead::begin(int flag) {
    print("Starting boxhead");

    if (flag == 0) {
        Logger::getInstance().setMode(LogMode::FULL);
        print("Flag");
    }

    players_.push_back(Player("Jakob"));

    graphic_.addObject(&players_.front(), "assets/arrow.png");
    
    if (!initialize()) {
        return;
    }
    start();
}

bool BoxHead::initialize() {
    Input::getInstance().setExitCallback(std::bind(&BoxHead::quit, this));

    if (!graphic_.begin(1800, 0)) {
        return false;
    }

    // Initialize players
    for (auto &player : players_) {
        using namespace std::placeholders;
        player.initialize();

        Input::getInstance().registerCallback(std::bind( std::bind(&Player::moveForward, player, _1), PLAYER_MOVEMENT_SPEED), SDLK_UP );
        Input::getInstance().registerCallback(std::bind( std::bind(&Player::moveBackward, player, _1), PLAYER_MOVEMENT_SPEED), SDLK_DOWN );
        Input::getInstance().registerCallback(std::bind( std::bind(&Player::rotateRight, player, _1), PLAYER_ROTATE_SPEED), SDLK_RIGHT);
        Input::getInstance().registerCallback(std::bind( std::bind(&Player::rotateLeft, player, _1), PLAYER_ROTATE_SPEED), SDLK_LEFT);
    }

    return true;
}

void BoxHead::start() {
    isRunning_ = true;

    while (isRunning_) {
        graphic_.update();
        Input::getInstance().check();
        // players_.begin()->getData();
    }
}

void BoxHead::quit() {
    isRunning_ = false;
}

