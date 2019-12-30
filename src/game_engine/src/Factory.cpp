#include "GameEngine/Factory.hpp"

#include <vector>

#include "Player/Player.hpp"
#include "Drawable/Drawable.hpp"
#include "Sprite/Sprite.hpp"

using namespace game_engine;

std::shared_ptr<components::Player> Factory::createPlayer(std::string name)
{
    // Position
    auto position = std::make_shared<components::Position_T>();
    position->x = std::make_shared<float>(250);
    position->y = std::make_shared<float>(250);
    position->angle = std::make_shared<float>(0);

    // Create drawable objects
    auto imageStill = std::make_unique<components::Drawable_T>();
    imageStill->imagePath = std::string("assets/player_green_still.png");
    imageStill->width = std::make_shared<uint32_t>(22);
    imageStill->height = std::make_shared<uint32_t>(41);
    imageStill->posX = position->x;
    imageStill->posY = position->y;
    imageStill->angle = position->angle;
    auto drawableStill = std::make_shared<components::Drawable>(std::move(imageStill));

    auto imageMoveLeft = std::make_unique<components::Drawable_T>();
    imageMoveLeft->imagePath = std::string("assets/player_green_left.png");
    imageMoveLeft->width = std::make_shared<uint32_t>(22);
    imageMoveLeft->height = std::make_shared<uint32_t>(44);
    imageMoveLeft->posX = position->x;
    imageMoveLeft->posY = position->y;
    imageMoveLeft->angle = position->angle;
    auto drawableLeft = std::make_shared<components::Drawable>(std::move(imageMoveLeft));

    auto imageMoveRight = std::make_unique<components::Drawable_T>();
    imageMoveRight->imagePath = std::string("assets/player_green_right.png");
    imageMoveRight->width = std::make_shared<uint32_t>(22);
    imageMoveRight->height = std::make_shared<uint32_t>(44);
    imageMoveRight->posX = position->x;
    imageMoveRight->posY = position->y;
    imageMoveRight->angle = position->angle;
    auto drawableRight = std::make_shared<components::Drawable>(std::move(imageMoveRight));

    std::vector<std::shared_ptr<components::Drawable>> drawables;
    drawables.push_back(drawableStill);
    drawables.push_back(drawableLeft);
    drawables.push_back(drawableRight);

    // Movable
    auto playerSprite = std::make_shared<components::Sprite>(drawables);
    auto movable = std::make_shared<components::Movable>(position, playerSprite);

    // Player
    auto player = std::make_shared<components::Player>(name.c_str(), movable, playerSprite);
    return player;
}
