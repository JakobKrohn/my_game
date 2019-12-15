#include "GameEngine/GameEngine.hpp"

#include <iostream>
#include <functional>

#include "Logger/Logger.hpp"
#include "Graphics/Drawable.hpp"
#include "Player/Player.hpp"
#include "Movable/Movable.hpp"

using namespace game_engine;

GameEngine::GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent, std::shared_ptr<graphics::Graphics_I> graphics) : m_active(false)
{
    m_inputEvent = inputEvent;
    m_graphics = graphics;

    initializeKeys();

    graphics::Position_T positionData;
    positionData.x = 0;
    positionData.y = 0;
    positionData.angle = 0;

    graphics::Drawable_T playerDrawable;
    playerDrawable.imagePath = "assets/arrow.png";
    playerDrawable.width = 100;
    playerDrawable.height = 100;
    playerDrawable.position = positionData;

    auto player = std::make_shared<components::Player>("Jakob", playerDrawable);

    m_graphics->addElement(player);

    {
        using namespace std::placeholders;
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Player::rotateLeft, player, _1), 10), input_event::input_key::LEFT);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Player::rotateRight, player, _1), 10), input_event::input_key::RIGHT);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Player::moveForward, player, _1), 10), input_event::input_key::UP);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Player::moveBackward, player, _1), 10), input_event::input_key::DOWN);
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
