#include "SdlInputEvent/SdlInputEvent.hpp"

using namespace sdl_input_event;

void SdlInputEvent::registerCallback(std::function<void()> callback, input_event::input_key key)
{
    m_callbacks.emplace(std::make_pair(translateKey(key), callback));
}

void SdlInputEvent::setExitCallback(std::function<void()> callback)
{
    m_exitCallback = callback;
}

void SdlInputEvent::check()
{
    while (SDL_PollEvent(&m_event))
    {
        if (m_event.type == SDL_QUIT || m_event.key.keysym.sym == SDLK_ESCAPE)
        {
            executeCallback(m_exitCallback);
        }

        if (m_event.type == SDL_KEYDOWN)
        {
            auto it = m_callbacks.find(m_event.key.keysym.sym);
            if (it != m_callbacks.end())
            {
                executeCallback(it->second);
            }
        }
    }
}

void SdlInputEvent::executeCallback(std::function<void()> callback)
{
    try
    {
        callback();
    }
    catch (std::exception &e)
    {
        throw std::runtime_error(e.what());
        // print("Callback excepetion: " + std::string("") + std::string(e.what()));
    }
}

SDL_Keycode SdlInputEvent::translateKey(input_event::input_key key)
{
    switch (key)
    {
    case input_event::input_key::LEFT:
        return SDLK_LEFT;
    case input_event::input_key::RIGHT:
        return SDLK_RIGHT;
    case input_event::input_key::UP:
        return SDLK_UP;
    case input_event::input_key::DOWN:
        return SDLK_DOWN;
    case input_event::input_key::SPACE:
        return SDLK_SPACE;
    case input_event::input_key::ESCAPE:
        return SDLK_ESCAPE;
    case input_event::input_key::SHIFT:
        return SDLK_LSHIFT;
    case input_event::input_key::Q:
        return SDLK_q;
    case input_event::input_key::W:
        return SDLK_w;
    case input_event::input_key::E:
        return SDLK_e;
    case input_event::input_key::R:
        return SDLK_r;
    case input_event::input_key::T:
        return SDLK_t;
    case input_event::input_key::Y:
        return SDLK_y;
    case input_event::input_key::U:
        return SDLK_u;
    case input_event::input_key::I:
        return SDLK_i;
    case input_event::input_key::O:
        return SDLK_o;
    case input_event::input_key::P:
        return SDLK_p;
    case input_event::input_key::A:
        return SDLK_a;
    case input_event::input_key::S:
        return SDLK_s;
    case input_event::input_key::D:
        return SDLK_d;
    case input_event::input_key::F:
        return SDLK_f;
    case input_event::input_key::G:
        return SDLK_g;
    case input_event::input_key::H:
        return SDLK_h;
    case input_event::input_key::J:
        return SDLK_j;
    case input_event::input_key::K:
        return SDLK_k;
    case input_event::input_key::L:
        return SDLK_l;
    case input_event::input_key::Z:
        return SDLK_z;
    case input_event::input_key::X:
        return SDLK_x;
    case input_event::input_key::C:
        return SDLK_c;
    case input_event::input_key::V:
        return SDLK_v;
    case input_event::input_key::B:
        return SDLK_b;
    case input_event::input_key::N:
        return SDLK_n;
    case input_event::input_key::M:
        return SDLK_m;

    default:
        throw std::runtime_error("Key not present");
    }
}