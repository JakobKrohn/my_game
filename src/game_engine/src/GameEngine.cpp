#include "GameEngine/GameEngine.hpp"

#include <chrono>
#include <functional>
#include <iostream>
#include <math.h>
#include <thread>

#include "GameEngine/internal/Factory.hpp"
#include "GameEngine/internal/Settings.hpp"
#include "Logger/Logger.hpp"
#include "Movable/Movable.hpp"
#include "Player/Player.hpp"

// TODO: This cannot be here.
input_event::PlayerControls_T defaultPlayerOneControls = {
    input_event::input_key::LEFT, input_event::input_key::RIGHT,
    input_event::input_key::UP, input_event::input_key::DOWN,
    input_event::input_key::SPACE};

using namespace game_engine;

GameEngine::GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent,
                       std::shared_ptr<Graphics_I> graphics)
    : m_active(false)
{
    m_inputEvent = inputEvent;
    m_graphics = graphics;

    print("Game initializing");

    m_background = m_graphics->createTileMap(
        "assets/backgrounds/backgrounddetailed1_edit.png");

    // Create and add player
    m_player = Factory::createPlayer("Jakob");
    m_graphics->addElement(m_player->getSprite());

    initializeKeys();

    // Player text top right
    m_playerText =
        m_graphics->createText("assets/fonts/OpenSans-Light.ttf", 14);
    m_playerText->setText("Hello from game engine!\nnew line!");
    m_playerText->setTextColor({0, 0, 0, 255});
    m_playerText->setLocation(TextLocation::TOP_LEFT);

    // Info text bottom
    m_infoText = m_graphics->createText("assets/fonts/OpenSans-Light.ttf", 14);
    m_infoText->setTextColor({0x00, 0x00, 0x00, 0xFF});
    m_infoText->setLocation(TextLocation::BOTTOM_CENTER);

    // Set resize event callback
    using namespace std::placeholders;
    m_graphics->setResizeEventCallback(
        std::bind(&GameEngine::resizeEventCallback, this, _1, _2));
}

void GameEngine::start()
{
    print("Starting game ...");
    m_active = true;

    while (m_active.load())
    {
        m_inputEvent->check();

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
    setPlayerKeys(m_player, defaultPlayerOneControls);
    // TODO: F11 should go to fullscreen
}

void GameEngine::setPlayerKeys(std::shared_ptr<components::Player> player,
                               input_event::PlayerControls_T controls)
{
    using namespace std::placeholders;
    using namespace input_event;

    m_inputEvent->registerCallback(
        std::bind(std::bind(&components::Player::rotateLeft, player, _1),
                  PLAYER_ROTATE_SPEED),
        controls.left);

    m_inputEvent->registerCallback(
        std::bind(std::bind(&components::Player::rotateRight, player, _1),
                  PLAYER_ROTATE_SPEED),
        controls.right);

    m_inputEvent->registerCallback(
        std::bind(std::bind(&components::Player::moveForward, player, _1),
                  PLAYER_MOVEMENT_SPEED),
        controls.up);

    m_inputEvent->registerCallback(
        std::bind(std::bind(&components::Player::moveBackward, player, _1),
                  PLAYER_MOVEMENT_SPEED),
        controls.down);
}

void GameEngine::printPlayerInfo(std::shared_ptr<components::Player> player,
                                 std::shared_ptr<Text_I> text)
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
    stream << static_cast<int>(
                  log_lib::Logger::getInstance().getNumberOfStartups())
           << " |  Window width: "
           << static_cast<int>(*m_graphics->getWindowWidth())
           << " |  Window height: "
           << static_cast<int>(*m_graphics->getWindowHeight())
           << " |  Horizontal tiles: " << hor << " |  Vertical tiles: " << ver;

    m_infoText->setText(stream.str().c_str());
}

void GameEngine::updateMap()
{
    if (!m_player->getMovable()->isMoving())
        return;

    m_background->getHorizontalGround() -=
        sin(*m_player->getMovable()->getPosition()->angle * M_PI / 180.0) *
        (MAP_MOVEMENT_SPEED);
    m_background->getVerticalGround() +=
        cos(*m_player->getMovable()->getPosition()->angle * M_PI / 180.0) *
        (MAP_MOVEMENT_SPEED);
}

void GameEngine::resizeEventCallback(uint32_t newWidth, uint32_t newHeight)
{
    print("Resize event, new window size: w:", newWidth, " h: ", newHeight);

    // TODO: This is not a good solution for keeping the player on the map.
    auto leftSide = newWidth / 10;
    auto rightSide = leftSide * 9;
    auto topSide = newHeight / 10;
    auto bottomSide = topSide * 9;
    m_player->getMovable()->setBoundaries(
        {leftSide, topSide, rightSide, bottomSide});

    auto pos = m_player->getMovable()->getPosition();
    m_player->getMovable()->setPosition((newWidth / 2), (newHeight / 2),
                                        *pos->angle);
    m_background->resizeEvent(newWidth, newHeight);
}