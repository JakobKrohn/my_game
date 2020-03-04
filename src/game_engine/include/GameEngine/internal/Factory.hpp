#ifndef GAME_ENGINE_FACTORY_HPP
#define GAME_ENGINE_FACTORY_HPP

#include <memory>

#include "GraphicsInterface/Sprite_I.hpp"
#include "Player/Player.hpp"

namespace game_engine
{

class Factory
{
  public:
    static std::shared_ptr<components::Player>
    createPlayer(std::string name, std::shared_ptr<Sprite_I> sprite);

  private:
};

} // namespace game_engine

#endif // GAME_ENGINE_FACTORY_HPP