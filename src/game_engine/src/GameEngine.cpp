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

    print("Game initializing");

    initializeKeys();

    // Create and add background
    auto background = std::make_unique<components::Drawable_T>();
    background->imagePath = "assets/yellow.png";
    background->width = m_graphics->getWindowWidth();
    background->height = m_graphics->getWindowHeight();
    background->posX = std::make_shared<float>(0);
    background->posY = std::make_shared<float>(0);
    background->angle = std::make_shared<float>(0);
    background->imageSize = {50, 50, 500, 500}; // x, y, w, h
    m_background = std::make_shared<components::Drawable>(std::move(background));
    m_graphics->addImage(m_background);

    // Create and add player
    m_player = Factory::createPlayer("Jakob");
    m_graphics->addElement(m_player->getSprite());

    {
        using namespace std::placeholders;
        using namespace input_event;

        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateLeft, m_player->getMovable(), _1), 2), input_key::LEFT);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateRight, m_player->getMovable(), _1), 2), input_key::RIGHT);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveForward, m_player->getMovable(), _1), 2), input_key::UP);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveBackward, m_player->getMovable(), _1), 2), input_key::DOWN);
    }

    // Create some text
    m_playerText = m_graphics->createText("assets/fonts/OpenSans-Bold.ttf", 14);
    print("my text: ", m_playerText);
    m_playerText->setText("Hello from game engine!\nnew line!");
    m_playerText->setTextColor({0, 0, 0, 255});
    m_playerText->setBackground(100, 100, {0xFF, 0x00, 0xFF, 0xFF});
    m_playerText->setLocation(TextLocation::BOTTOM_RIGHT);

    // Set resize event callback
    using namespace std::placeholders;
    m_graphics->setResizeEventCallback(std::bind(&GameEngine::resizeEventCallback, this, _1, _2));
}

void GameEngine::start()
{
    print("Starting game ...");
    m_active = true;

    while (m_active)
    {
        m_inputEvent->check();
        printPlayerInfo(m_player, m_playerText);
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
    
    // F11 goes to fullscreen
    
}

void GameEngine::printPlayerInfo(std::shared_ptr<components::Player> player, std::shared_ptr<Text_I> text)
{
    auto pos = player->getMovable()->getPosition();
    std::ostringstream stream;
    stream << player->getName() << "\n";
    stream << "x:" << static_cast<int>(*pos->x)
           << " y:" << static_cast<int>(*pos->y)
           << " deg:" << static_cast<int>(*pos->angle) << "\n";
    text->setText(stream.str().c_str());
    // text->setText("testing");
    text->draw();
}

void GameEngine::resizeEventCallback(uint32_t newWidth, uint32_t newHeight)
{
    print("Resize event, new window size: w:", newWidth, " h: ", newHeight);

    auto pos = m_player->getMovable()->getPosition();
    m_player->getMovable()->setPosition((newWidth / 2), (newHeight / 2), *pos->angle);
}