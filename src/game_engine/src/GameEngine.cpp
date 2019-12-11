#include "GameEngine/GameEngine.hpp"

#include <iostream>

using namespace game_engine;

GameEngine::GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent, std::shared_ptr<graphics::Graphics_I> graphics)
{
    m_inputEvent = inputEvent;
    m_graphics = graphics;
}
