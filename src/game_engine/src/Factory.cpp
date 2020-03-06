#include "GameEngine/internal/Factory.hpp"

#include <vector>

#include "Movable/Movable.hpp"
#include "Player/Player.hpp"

using namespace game_engine;

std::shared_ptr<components::Player>
Factory::createPlayer(std::string name, std::shared_ptr<Sprite_I> sprite)
{
    auto movable = std::make_shared<components::Movable>();
    return std::make_shared<components::Player>(name.c_str(), movable,
                                                sprite);
}
