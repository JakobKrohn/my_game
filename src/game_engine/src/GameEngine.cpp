#include "GameEngine/GameEngine.hpp"

#include <iostream>
#include <functional>

using namespace game_engine;

GameEngine::GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent, std::shared_ptr<graphics::Graphics_I> graphics) :
    m_active(false)
{
    m_inputEvent = inputEvent;
    m_graphics = graphics;

    initializeKeys();
}

void GameEngine::start()
{
    m_active = true;
    while (m_active)
    {
        m_inputEvent->check();
    }
}

void GameEngine::exit()
{
    m_active = false;
}

void GameEngine::initializeKeys()
{
    m_inputEvent->setExitCallback(std::bind(&GameEngine::exit, this));
}

