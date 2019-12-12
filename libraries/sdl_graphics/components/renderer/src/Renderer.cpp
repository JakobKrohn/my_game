#include "Renderer/Renderer.hpp"

using namespace sdl_graphics;

Renderer::Renderer(std::shared_ptr<Window> window, int index, uint32_t flag)
{
    m_renderer = SDL_CreateRenderer(window->getSdlObject(), index, flag);

    if (m_renderer == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
}