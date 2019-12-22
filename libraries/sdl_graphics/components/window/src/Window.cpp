#include "Window/Window.hpp"

#include <stdexcept>

using namespace sdl_graphics;

Window::Window(uint16_t positionX, uint16_t positionY, uint16_t width, uint16_t height, uint32_t flag)
{
    m_window = SDL_CreateWindow("window", positionX, positionY, width, height, flag);
    // m_window = SDL_CreateWindow("window", 0,0,0,0,SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (m_window == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }

    m_position = {positionX, positionY, width, height};
    // m_size = {(positionX + width), (positionY + height)};
}

Window::~Window()
{
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}

SDL_Window *Window::get() const
{
    return m_window;
}