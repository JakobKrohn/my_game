#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

/** Game Engine 
 * Holds all vital objects for the game to run
*/

#include <memory>

#include "InputEvent/InputEvent_I.hpp"
#include "GraphicsInterface/Graphics_I.hpp"
#include "GraphicsInterface/Text_I.hpp"
#include "GraphicsInterface/TileMap_I.hpp"
#include "Player/Player.hpp"
#include "Drawable/Drawable.hpp"

namespace game_engine
{

class GameEngine
{
public:
    GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent, std::shared_ptr<Graphics_I> graphics);

    void start();
    void exit();

private:
    std::shared_ptr<input_event::InputEvent_I> m_inputEvent;
    std::shared_ptr<Graphics_I> m_graphics;
    std::shared_ptr<components::Player> m_player; // TODO: interface?
    std::shared_ptr<TileMap_I> m_background;
    std::shared_ptr<Text_I> m_playerText;
    std::shared_ptr<Text_I> m_infoText;
    bool m_active;

    void initializeKeys();
    void printPlayerInfo(std::shared_ptr<components::Player> player, std::shared_ptr<Text_I> text);
    void printInfo() const;
    void updateMap();
    void resizeEventCallback(uint32_t newWidth, uint32_t newHeight);
};

} // namespace game_engine

#endif // GAME_ENGINE_HPP