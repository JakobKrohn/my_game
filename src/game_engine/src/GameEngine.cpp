#include "GameEngine/GameEngine.hpp"

#include <iostream>
#include <functional>
#include <thread>
#include <chrono>
#include <math.h>

#include "Logger/Logger.hpp"
#include "Player/Player.hpp"
#include "Movable/Movable.hpp"
#include "GameEngine/internal/Factory.hpp"

using namespace game_engine;

GameEngine::GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent, std::shared_ptr<Graphics_I> graphics) : m_active(false)
{
    m_inputEvent = inputEvent;
    m_graphics = graphics;

    print("Game initializing");

    initializeKeys();

    m_background = m_graphics->createTileMap("assets/backgrounds/backgrounddetailed1_edit.png");

    // Create and add player
    m_player = Factory::createPlayer("Jakob");
    m_graphics->addElement(m_player->getSprite());

    {
        using namespace std::placeholders;
        using namespace input_event;

        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateLeft, m_player->getMovable(), _1), 5), input_key::LEFT);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateRight, m_player->getMovable(), _1), 5), input_key::RIGHT);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveForward, m_player->getMovable(), _1), 3), input_key::UP);
        m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveBackward, m_player->getMovable(), _1), 3), input_key::DOWN);
    }

    // Player text top right
    m_playerText = m_graphics->createText("assets/fonts/OpenSans-Light.ttf", 14);
    m_playerText->setText("Hello from game engine!\nnew line!");
    m_playerText->setTextColor({0, 0, 0, 255});
    m_playerText->setLocation(TextLocation::TOP_LEFT);

    // Info text bottom
    m_infoText = m_graphics->createText("assets/fonts/OpenSans-Light.ttf", 14);
    m_infoText->setTextColor({0x00, 0x00, 0x00, 0xFF});
    m_infoText->setLocation(TextLocation::BOTTOM_CENTER);

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

        auto leftSide = *m_graphics->getWindowWidth() / 3;
        auto rightSide = leftSide * 2;
        auto topSide = *m_graphics->getWindowHeight() / 3;
        auto bottomSide = topSide * 2;
        m_player->getMovable()->setBoundaries({leftSide, topSide, rightSide, bottomSide});
        printPlayerInfo(m_player, m_playerText);
        printInfo();
        updateMap();
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
    text->draw();
}

void GameEngine::printInfo() const
{
    auto [hor, ver] = m_background->getNumberOfTiles();
    std::ostringstream stream;
    stream << "Startups: ";
    stream << static_cast<int>(log_lib::Logger::getInstance().getNumberOfStartups())
           << " |  Window width: " << static_cast<int>(*m_graphics->getWindowWidth())
           << " |  Window height: " << static_cast<int>(*m_graphics->getWindowHeight())
           << " |  Horizontal tiles: " << hor
           << " |  Vertical tiles: " << ver;

    m_infoText->setText(stream.str().c_str());
}

void GameEngine::updateMap()
{
    auto leftSide = *m_graphics->getWindowWidth() / 3;
    auto rightSide = leftSide * 2;
    auto topSide = *m_graphics->getWindowHeight() / 3;
    auto bottomSide = topSide * 2;

    if (!m_player->getMovable()->isMoving())
        return;

    if (*m_player->getMovable()->getPosition()->x <= leftSide)
    {
        m_background->getHorizontalGround() -= sin(*m_player->getMovable()->getPosition()->angle * M_PI / 180.0) * 3;
    }
    if (*m_player->getMovable()->getPosition()->x >= rightSide)
    {
        m_background->getHorizontalGround() -= sin(*m_player->getMovable()->getPosition()->angle * M_PI / 180.0) * 3;
    }

    if (*m_player->getMovable()->getPosition()->y <= topSide)
    {
        m_background->getVerticalGround() += cos(*m_player->getMovable()->getPosition()->angle * M_PI / 180.0) * 3;
    }

    if (*m_player->getMovable()->getPosition()->y >= bottomSide)
    {
            m_background->getVerticalGround() += cos(*m_player->getMovable()->getPosition()->angle * M_PI / 180.0) * 3;
    }
}

void GameEngine::resizeEventCallback(uint32_t newWidth, uint32_t newHeight)
{
    print("Resize event, new window size: w:", newWidth, " h: ", newHeight);

    auto pos = m_player->getMovable()->getPosition();
    m_player->getMovable()->setPosition((newWidth / 2), (newHeight / 2), *pos->angle);
}