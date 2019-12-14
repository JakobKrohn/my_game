#ifndef SDL_INPUT_EVENT_HPP
#define SDL_INPUT_EVENT_HPP

#include <functional>
#include <map>

#include "InputEvent/InputEvent_I.hpp"

#include "SDL.h"

namespace sdl_input_event
{
class SdlInputEvent : public input_event::InputEvent_I
{
public:
    void registerCallback(std::function<void()> callback, input_event::input_key key);
    void setExitCallback(std::function<void()> callback);

    void check();

private:
    SDL_Event m_event;
    std::function<void()> m_exitCallback;
    std::map<SDL_Keycode, std::function<void()>> m_callbacks;

    void executeCallback(std::function<void()> callback);
    SDL_Keycode translateKey(input_event::input_key key);
};
} // namespace sdl_input_event

#endif // SDL_INPUT_EVENT_HPP