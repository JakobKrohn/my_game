#include "GameEngine/GameEngine.hpp"

#include <iostream>

using namespace game_engine;

GameEngine::GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent)
{
    m_inputEvent = inputEvent;
}
