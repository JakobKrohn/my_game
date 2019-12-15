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

    graphics::Drawable_T drawData {
        "assets/arrow.png", 100, 100, 100, 0, 0
    };

    components::position_T playerPosition;
    playerPosition.posX = 0;
    playerPosition.posY = 0;
    playerPosition.angle = 0;

    graphics::Drawable_T playerDrawable;
    playerDrawable.imagePath = "assets/arrow.png";
    playerDrawable.width = 100;
    playerDrawable.height = 100;
    playerDrawable.posX = playerPosition.posX;
    playerDrawable.posY = playerPosition.posY;
    playerDrawable.angle = playerPosition.angle;

    auto player = std::make_shared<components::Player>("Jakob", playerPosition, playerDrawable);
    m_graphics->addElement(player);
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
