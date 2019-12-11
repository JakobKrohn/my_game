#include "Window/Window.hpp"

#include <stdexcept>

using namespace sdl_graphics;

Window::Window(uint32_t positionX, uint32_t positionY, uint32_t width, uint32_t height, uint32_t flag)
{
    m_window = SDL_CreateWindow("", positionX, positionY, width, height, flag);

    if (m_window == nullptr) 
    {
        throw std::runtime_error(SDL_GetError());
    }
}

Window::~Window()
{
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}