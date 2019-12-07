#ifndef SDL_INPUT_EVENT_HPP
#define SDL_INPUT_EVENT_HPP

#include <functional>

#include "InputEvent/InputEvent_I.hpp"

#include "SDL.h"

namespace sdl_input_event
{
class SdlInputEvent : public input_event::InputEvent_I
{
public:
    void registerCallback(std::function<void()> callback, input_event::input_key key);
    void setExitCallback(std::function<void()> callback);

private:
    // SDL_Event m_event;
};
} // namespace sdl_input_event

#endif // SDL_INPUT_EVENT_HPP