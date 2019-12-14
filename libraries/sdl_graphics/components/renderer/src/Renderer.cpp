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

SDL_Renderer *Renderer::getSdlObject() const
{
    return m_renderer;
}

void Renderer::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
    SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
}

void Renderer::clear()
{
    SDL_RenderClear(m_renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(m_renderer);
}