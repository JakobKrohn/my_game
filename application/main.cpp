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

int main(int argc, char **argv)
{
    Logger::getInstance().setMode(LogMode::TERMINAL);
    
    print("Application");
    if (argc > 1)
    {
        std::cout << argv[1] << "\n";
    }
    else
    {
        std::cout << "no args\n";
    }

    auto inputEvent = std::make_shared<sdl_input_event::SdlInputEvent>();
    auto graphics = std::make_shared<sdl_graphics::SdlGraphics>();

    auto gameEngine = std::make_unique<game_engine::GameEngine>(inputEvent, graphics);

    gameEngine->start();

    return 0;
}
