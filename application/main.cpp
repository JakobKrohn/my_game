#include <iostream>
#include <memory>

#include "Movable/Movable.hpp"
#include "Player/Player.hpp"
#include "InputEvent/InputEvent_I.hpp"

#include "GameEngine/GameEngine.hpp"

#include "SdlInputEvent/SdlInputEvent.hpp"

int main(int argc, char **argv)
{
    std::cout << "Application\n";
    
    if (argc > 1)
    {
        std::cout << argv[1] << "\n";
    }
    else
    {
        std::cout << "no args\n";
    }

    auto inputEvent = std::make_shared<sdl_input_event::SdlInputEvent>();
    auto gameEngine = std::make_unique<game_engine::GameEngine>(inputEvent);

    // component::Player player("name");
    // component::Movable movable;
    // input_event::InputEvent_I input;

    // input_event::InputEvent_I *inputEvent;
    // inputEvent = new sdl_input_event::SdlInputEvent();

    return 0;
}
