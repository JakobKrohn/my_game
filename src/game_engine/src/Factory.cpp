#include "GameEngine/Factory.hpp"

#include <vector>

#include "Player/Player.hpp"

using namespace game_engine;

std::shared_ptr<components::Player> Factory::createPlayer(std::string name)
{
    // graphics::Position_T positionData;
    // positionData.x = 250;
    // positionData.y = 250;
    // positionData.angle = 0;

    // graphics::Image_T imageStill;
    // imageStill.imagePath = "assets/player_green_still.png";
    // imageStill.width = 22;
    // imageStill.height = 41;
    // imageStill.position = positionData;

    // graphics::Image_T imageMoveLeft;
    // imageMoveLeft.imagePath = "assets/player_green_left.png";
    // imageMoveLeft.width = 22;
    // imageMoveLeft.height = 44;
    // imageMoveLeft.position = positionData;

    // graphics::Image_T imageMoveRight;
    // imageMoveRight.imagePath = "assets/player_green_right.png";
    // imageMoveRight.width = 22;
    // imageMoveRight.height = 44;
    // imageMoveRight.position = positionData;

    // std::vector<graphics::Image_T> imageData;

    // // auto player = std::make_shared<components::Player>(name.c_str(), imageData);
    // auto player = std::make_shared<components::Player>(name.c_str(), imageStill);
    // return player;
}
