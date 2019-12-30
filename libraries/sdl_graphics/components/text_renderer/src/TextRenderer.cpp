#include "TextRenderer/TextRenderer.hpp"

using namespace sdl_graphics;

TextRenderer::TextRenderer(uint posX, uint posY, SDL_Color color, std::shared_ptr<Renderer> renderer) : m_posX(posX), m_posY(posY), m_color(color)
{
    m_renderer = renderer;
    m_font = TTF_OpenFont("assets/fonts/OpenSans-Bold.ttf", 20);
    if (m_font == NULL)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

TextRenderer::TextRenderer(std::string fontPath, uint8_t fontSize, std::shared_ptr<Renderer> renderer) : m_renderer(renderer)
{
    // Set default members!!

    m_font = TTF_OpenFont("assets/fonts/OpenSans-Bold.ttf", 20);
    if (m_font == NULL)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

void TextRenderer::setLocation(TextLocation location)
{
    m_location = location;
}

void TextRenderer::setTextColor(SDL_Color color)
{
    m_color = color;
}

void TextRenderer::setBackgroundColor(SDL_Color color)
{
    m_backgroundColor = color;
}

void TextRenderer::setPadding(uint8_t padding)
{
    m_padding = padding;
}

void TextRenderer::render(std::string text)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(m_font, text.c_str(), m_color);
    if (textSurface == nullptr)
    {
        throw std::runtime_error("Could not create surface from string");
    }

    auto texture = SDL_CreateTextureFromSurface(m_renderer->get(), textSurface);
    if (texture = nullptr)
    {
        throw std::runtime_error("Could not create texture from surface");
    }

    auto width = textSurface->w;
    auto height = textSurface->h;

    auto pos = calculatePosition(width, height);

    auto backgroundWidth = width + m_padding;
    auto backgroundHeight = height + m_padding;

    SDL_Rect renderQuad = {(int)m_posX, (int)m_posY, width, height};

    SDL_FreeSurface(textSurface);
    SDL_RenderCopyEx(m_renderer->get(), texture, NULL, &renderQuad, 0, NULL, SDL_FLIP_NONE);
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

std::tuple<uint, uint> TextRenderer::calculatePosition(uint textWidth, uint textHeight)
{
    auto [wWidth, wHeight] = m_renderer->getWindowSize();

    switch (m_location)
    {
    case TextLocation::TOP_LEFT:
        return std::make_tuple(0, 0);
        break;
    case TextLocation::TOP_CENTER:
        // uint x = (wWidth / 2) - (textWidth / 2);
        // uint y = (wHeight / 2) - (textHeight / 2);
        break;
    case TextLocation::TOP_RIGHT:
        /* code */
        break;
    case TextLocation::BOTTOM_LEFT:
        /* code */
        break;
    case TextLocation::BOTTOM_CENTER:
        /* code */
        break;
    case TextLocation::BOTTOM_RIGHT:
        /* code */
        break;
    case TextLocation::FLOATING:
        /* code */
        break;

    default:
        break;
    }
}