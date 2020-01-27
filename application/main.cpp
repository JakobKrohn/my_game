#include <iostream>
#include <memory>

#include "Movable/Movable.hpp"
#include "Player/Player.hpp"
#include "Logger/Logger.hpp"

#include "InputEvent/InputEvent_I.hpp"
#include "GraphicsInterface/Graphics_I.hpp"

#include "GameEngine/GameEngine.hpp"

#include "SdlInputEvent/SdlInputEvent.hpp"
#include "SdlGraphics/SdlGraphics.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

int main(int argc, char **argv)
{
    log_lib::Logger::getInstance().setMode(log_lib::Mode::FULL);
    const uint8_t numberOfPlayers = 2;

    if (argc > 1)
    {
    }
    else
    {
    }

    auto inputEvent = std::make_shared<sdl_input_event::SdlInputEvent>();
    auto graphics = std::make_shared<sdl_graphics::SdlGraphics>();

    auto gameEngine = std::make_unique<game_engine::GameEngine>(inputEvent, graphics, numberOfPlayers);

    gameEngine->start();

    return 0;
}

#pragma GCC diagnostic pop
