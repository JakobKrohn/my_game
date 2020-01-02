#include "TextRenderer/TextRenderer.hpp"

using namespace sdl_graphics;

TextRenderer::TextRenderer(std::string fontPath, uint8_t fontSize, std::shared_ptr<Renderer> renderer)
    : m_renderer(renderer),
      m_location(TextLocation::TOP_LEFT),
      m_color({255, 255, 255, 255}),
      m_backgroundColor({0, 0, 0, 255}),
      m_padding(0),
      m_drawBackground(false)
{
    m_font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (m_font == NULL)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

void TextRenderer::setBackground(uint width, uint height, SDL_Color color)
{
    auto [x, y] = calculatePosition(width, height);
    m_background.x = x;
    m_background.y = y;
    m_background.w = width;
    m_background.h = height;
    m_backgroundColor = color;
    m_drawBackground = true;
}

void TextRenderer::drawBackground(bool on)
{
    m_drawBackground = on;
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

void TextRenderer::reposition()
{
    auto [x, y] = calculatePosition(m_background.w, m_background.h);
    m_background.x = x;
    m_background.y = y;
}

void TextRenderer::render(std::string text)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(m_font, text.c_str(), m_color);
    if (textSurface == nullptr)
    {
        throw std::runtime_error("Could not create surface from string");
    }

    auto texture = SDL_CreateTextureFromSurface(m_renderer->get(), textSurface);
    if (texture == nullptr)
    {
        throw std::runtime_error("Could not create texture from surface");
    }

    auto width = textSurface->w;
    auto height = textSurface->h;

    auto [x, y] = calculatePosition(width, height);

    SDL_Rect renderQuad = {(int)x, (int)y, width, height};

    if (m_drawBackground)
    {
        reposition();

        m_renderer->setColor(m_backgroundColor.r, m_backgroundColor.g, m_backgroundColor.b, m_backgroundColor.a);
        SDL_RenderFillRect(m_renderer->get(), &m_background);
        SDL_RenderDrawRect(m_renderer->get(), &m_background);
    }

    SDL_RenderCopyEx(m_renderer->get(), texture, NULL, &renderQuad, 0, NULL, SDL_FLIP_NONE);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(texture);
}

std::tuple<uint, uint> TextRenderer::calculatePosition(uint textWidth, uint textHeight)
{
    auto [wWidth, wHeight] = m_renderer->getWindowSize();

    uint x, y;

    switch (m_location)
    {
    case TextLocation::TOP_LEFT:
        return std::make_tuple(0, 0);
        break;
    case TextLocation::TOP_CENTER:
        x = (wWidth / 2) - (textWidth / 2);
        y = 0;
        break;
    case TextLocation::TOP_RIGHT:
        x = wWidth - textWidth;
        y = 0;
        break;
    case TextLocation::BOTTOM_LEFT:
        x = 0;
        y = (wHeight - textHeight);
        break;
    case TextLocation::BOTTOM_CENTER:
        x = (wWidth / 2) - (textWidth / 2);
        y = (wHeight - textHeight);
        break;
    case TextLocation::BOTTOM_RIGHT:
        x = (wWidth) - (textWidth);
        y = (wHeight - textHeight);
        break;
    case TextLocation::FLOATING:
        /* code */
        break;

    default:
        break;
    }
    return std::make_tuple(x, y);
}