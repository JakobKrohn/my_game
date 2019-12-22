#include "GameEngine/Factory.hpp"

#include "Player/Player.hpp"

using namespace game_engine;

std::shared_ptr<components::Player> Factory::createPlayer(std::string name)
{
    graphics::Position_T positionData;
    positionData.x = 0;
    positionData.y = 0;
    positionData.angle = 0;

    graphics::Drawable_T playerDrawable;
    playerDrawable.imagePath = "assets/arrow.png";
    playerDrawable.width = 50;
    playerDrawable.height = 50;
    playerDrawable.position = positionData;

    auto player = std::make_shared<components::Player>(name.c_str(), playerDrawable);
    return player;
}