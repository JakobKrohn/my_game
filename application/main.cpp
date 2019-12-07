#include <iostream>

#include "Movable/Movable.hpp"
#include "Player/Player.hpp"
#include "InputEvent/InputEvent_I.hpp"

#include "GameEngine/GameEngine.hpp"

#include "SdlInputEvent/SdlInputEvent.hpp"
// #include "SDL.h"

int main(int argc, char **argv) {
    // component::Player player("name");
    // component::Movable movable;
    // input_event::InputEvent_I input;

    input_event::InputEvent_I * inputEvent;
    inputEvent = new sdl_input_event::SdlInputEvent();
    // SDL_Init(NULL);

    // sdl_input_event::SdlInputEvent* sie;
    
    if (argc > 1) {
        std::cout << argv[2] << "\n";
    }
    else {
    }
    return 0;
}
