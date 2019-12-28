#include "GameEngine/GameEngine.hpp"

#include <iostream>
#include <functional>
#include <thread>
#include <chrono>

#include "Logger/Logger.hpp"
#include "Player/Player.hpp"
#include "Movable/Movable.hpp"
#include "GameEngine/Factory.hpp"

using namespace game_engine;

GameEngine::GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent, std::shared_ptr<Graphics_I> graphics) : m_active(false)
{
    m_inputEvent = inputEvent;
    m_graphics = graphics;

    initializeKeys();

    auto player = Factory::createPlayer("Jakob");

    m_graphics->addElement(player->getMovable());

    {
        using namespace std::placeholders;
        using namespace input_event;

        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateLeft, player->getMovable(), _1), 2), input_key::LEFT);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateRight, player->getMovable(), _1), 2), input_key::RIGHT);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveForward, player->getMovable(), _1), 2), input_key::UP);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveBackward, player->getMovable(), _1), 2), input_key::DOWN);
    }
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
