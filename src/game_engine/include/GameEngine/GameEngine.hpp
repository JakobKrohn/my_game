#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

/** Game Engine 
 * Holds all vital objects for the game to run
*/

#include "InputEvent/InputEvent_I.hpp"
#include "Player/Player_I.hpp"

#include <memory>

namespace game_engine
{
class GameEngine
{
public:
    GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent);

private:
    std::shared_ptr<input_event::InputEvent_I> m_inputEvent;
    std::vector<component::Player_I> m_players;
};
} // namespace game_engine

#endif // GAME_ENGINE_HPP