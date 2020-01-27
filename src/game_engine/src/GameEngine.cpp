#include "GameEngine/GameEngine.hpp"

#include <iostream>
#include <functional>
#include <tuple>
#include <thread>
#include <chrono>
#include <math.h>

#include "Logger/Logger.hpp"
#include "Player/Player.hpp"
#include "Movable/Movable.hpp"
#include "GameEngine/internal/Factory.hpp"
#include "GameEngine/internal/Settings.hpp"

using namespace game_engine;

GameEngine::GameEngine(std::shared_ptr<input_event::InputEvent_I> inputEvent, std::shared_ptr<Graphics_I> graphics, uint8_t numberOfPlayers)
    : m_active(false)
{
    m_inputEvent = inputEvent;
    m_graphics = graphics;

    print("Game initializing");

    m_inputEvent->setExitCallback(std::bind(&GameEngine::exit, this));

    createPlayers(numberOfPlayers);

    initializeKeys();

    m_background = m_graphics->createTileMap("assets/backgrounds/backgrounddetailed1_edit.png");

    // Player text top right
    m_playerText.emplace_back(m_graphics->createText("assets/fonts/OpenSans-Light.ttf", 14));
    m_playerText.front()->setTextColor({0, 0, 0, 255});
    m_playerText.front()->setLocation(TextLocation::TOP_LEFT);

    m_playerText.emplace_back(m_graphics->createText("assets/fonts/OpenSans-Light.ttf", 14));
    m_playerText.back()->setTextColor({0, 0, 0, 255});
    m_playerText.back()->setLocation(TextLocation::TOP_RIGHT);

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

    // m_player->getMovable()->rotateRight(180);

    while (m_active)
    {
        m_inputEvent->check();

        auto leftSide = *m_graphics->getWindowWidth() / 10;
        auto rightSide = leftSide * 9;
        auto topSide = *m_graphics->getWindowHeight() / 10;
        auto bottomSide = topSide * 9;
        m_players.at(0)->getMovable()->setBoundaries({leftSide, topSide, rightSide, bottomSide});
        printPlayerInfo(m_players.at(0), m_playerText.front());
        printPlayerInfo(m_players.at(1), m_playerText.back());
        printInfo();
        updateMap();
        m_graphics->update();
        // m_player->getMovable()->moveForward(1);
    }
}

void GameEngine::exit()
{
    m_active = false;
}

void GameEngine::createPlayers(uint8_t numberOfPlayers)
{
    std::string defaultName = "Player";
    for (uint8_t i = 0; i < numberOfPlayers; i++)
    {
        std::string index = std::to_string(i);
        m_players.emplace_back(Factory::createPlayer(defaultName + index));
        m_graphics->addElement(m_players.at(i)->getSprite());
    }
}

void GameEngine::initializeKeys()
{
    using namespace std::placeholders;
    using namespace input_event;

    // for (auto [it, end, i] = std::tuple{m_players.begin(), m_players.end(), 0};
    //      it != end; ++it, ++i)
    // {
    //     it->get()->getMovable();
    //     m_inputEvent->registerCallback(std::bind(
    //                                        std::bind(&components::Movable::rotateLeft, it->get()->getMovable(), _1), PLAYER_ROTATE_SPEED),
    //                                    input_key::LEFT);

    //     m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateRight, it->get()->getMovable(), _1), PLAYER_ROTATE_SPEED), input_key::RIGHT);
    //     m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveForward, it->get()->getMovable(), _1), PLAYER_MOVEMENT_SPEED), input_key::UP);
    //     m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveBackward, it->get()->getMovable(), _1), PLAYER_MOVEMENT_SPEED), input_key::DOWN);
    // }

    m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateLeft,   m_players.at(0)->getMovable(), _1), PLAYER_ROTATE_SPEED),   input_key::LEFT);
    m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateRight,  m_players.at(0)->getMovable(), _1), PLAYER_ROTATE_SPEED),   input_key::RIGHT);
    m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveForward,  m_players.at(0)->getMovable(), _1), PLAYER_MOVEMENT_SPEED), input_key::UP);
    m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveBackward, m_players.at(0)->getMovable(), _1), PLAYER_MOVEMENT_SPEED), input_key::DOWN);

    m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateLeft,   m_players.at(1)->getMovable(), _1), PLAYER_ROTATE_SPEED),   input_key::A);
    m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::rotateRight,  m_players.at(1)->getMovable(), _1), PLAYER_ROTATE_SPEED),   input_key::D);
    m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveForward,  m_players.at(1)->getMovable(), _1), PLAYER_MOVEMENT_SPEED), input_key::W);
    m_inputEvent->registerCallback(std::bind(std::bind(&components::Movable::moveBackward, m_players.at(1)->getMovable(), _1), PLAYER_MOVEMENT_SPEED), input_key::S);
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
    auto leftSide = *m_graphics->getWindowWidth() / 10;
    auto rightSide = leftSide * 9;
    auto topSide = *m_graphics->getWindowHeight() / 10;
    auto bottomSide = topSide * 9;

    if (!m_players.at(0)->getMovable()->isMoving())
        return;

    m_background->getHorizontalGround() -= sin(*m_players.at(0)->getMovable()->getPosition()->angle * M_PI / 180.0) * (MAP_MOVEMENT_SPEED);
    m_background->getVerticalGround() += cos(*m_players.at(0)->getMovable()->getPosition()->angle * M_PI / 180.0) * (MAP_MOVEMENT_SPEED);
}

void GameEngine::resizeEventCallback(uint32_t newWidth, uint32_t newHeight)
{
    print("Resize event, new window size: w:", newWidth, " h: ", newHeight);

    auto pos = m_players.at(0)->getMovable()->getPosition();
    m_players.at(0)->getMovable()->setPosition((newWidth / 2), (newHeight / 2), *pos->angle);
    m_background->resizeEvent(newWidth, newHeight);
}