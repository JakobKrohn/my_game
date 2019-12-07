#include "SdlInputEvent/SdlInputEvent.hpp"

using namespace sdl_input_event;

void SdlInputEvent::registerCallback(std::function<void()> callback, input_event::input_key key)
{
    SDL_Init(NULL);
    // SDL_Window* window = NULL;

//     while (SDL_PollEvent(&m_event))
//     {
//         if (m_event.type == SDL_KEYDOWN)
//         {
            
//         }
//     }
}

void SdlInputEvent::setExitCallback(std::function<void()> callback)
{
}