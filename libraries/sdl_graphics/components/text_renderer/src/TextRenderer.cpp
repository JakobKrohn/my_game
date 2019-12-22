#include "TextRenderer/TextRenderer.hpp"

using namespace sdl_graphics;

TextRenderer::TextRenderer(uint posX, uint posY, SDL_Color color, std::shared_ptr<Renderer> renderer) : m_posX(posX), m_posY(posY), m_color(color)
{
    m_renderer = renderer;
    m_font = TTF_OpenFont("assets/fonts/OpenSans-Light.ttf", 20);
    if (m_font == NULL)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

void TextRenderer::renderText(std::string text)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(m_font, text.c_str(), m_color);
    if (textSurface != NULL)
    {
        auto texture = SDL_CreateTextureFromSurface(m_renderer->get(), textSurface);
        if (texture == NULL)
        {
            throw std::runtime_error("Could not create texture from surface");
        }

        auto mWidth = textSurface->w;
        auto mHeight = textSurface->h;

        SDL_Rect renderQuad = {(int)m_posX, (int)m_posY, mWidth, mHeight};

        SDL_FreeSurface(textSurface);
        SDL_RenderCopyEx(m_renderer->get(), texture, NULL, &renderQuad, 0, NULL, SDL_FLIP_NONE);
    }
}