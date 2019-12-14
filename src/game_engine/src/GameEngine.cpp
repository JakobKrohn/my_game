#include "GameEngine/GameEngine.hpp"

#include <iostream>
#include <functional>

#include "Logger/Logger.hpp"

using namespace game_engine;

GameEngine::GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent, std::shared_ptr<graphics::Graphics_I> graphics) : m_active(false)
{
    m_inputEvent = inputEvent;
    m_graphics = graphics;

    initializeKeys();

    auto draw = std::make_shared<graphics::Drawable>("assets/arrow.png", 100, 100);
    m_graphics->addElement(draw);
}

void GameEngine::start()
{
    print("Starting game ...");
    m_active = true;
    while (m_active)
    {
        m_inputEvent->check();
        m_graphics->update();
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
