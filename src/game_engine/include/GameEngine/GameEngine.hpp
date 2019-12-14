#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

/** Game Engine 
 * Holds all vital objects for the game to run
*/

#include <memory>

#include "InputEvent/InputEvent_I.hpp"
#include "Graphics/Graphics_I.hpp"
#include "Player/Player_I.hpp"

namespace game_engine
{
class GameEngine
{
public:
    GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent, std::shared_ptr<graphics::Graphics_I> graphics);

    void start();
    void exit();

private:
    std::shared_ptr<input_event::InputEvent_I> m_inputEvent;
    std::shared_ptr<graphics::Graphics_I> m_graphics;
    std::vector<component::Player_I> m_players;
    bool m_active;

    void initializeKeys();
};
} // namespace game_engine

#endif // GAME_ENGINE_HPP