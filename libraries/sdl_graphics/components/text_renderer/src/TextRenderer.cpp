#include "TextRenderer/TextRenderer.hpp"

using namespace sdl_graphics;

TextRenderer::TextRenderer(std::string fontPath, uint8_t fontSize, std::shared_ptr<Renderer> renderer)
    : m_renderer(renderer),
      m_location(TextLocation::FLOATING),
      m_color({255, 255, 255, 255}),
      m_backgroundColor({0, 0, 0, 255}),
      m_drawBackground(false)
{
    m_font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (m_font == NULL)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

TextRenderer::~TextRenderer()
{
    SDL_DestroyTexture(m_texture);
}

void TextRenderer::draw()
{
    if (m_text.length() < 1)
        return;
    
    if (m_drawBackground)
    {
        reposition();

        m_renderer->setColor(m_backgroundColor.r, m_backgroundColor.g, m_backgroundColor.b, m_backgroundColor.a);
        SDL_RenderFillRect(m_renderer->get(), &m_background);
        SDL_RenderDrawRect(m_renderer->get(), &m_background);
    }

    SDL_RenderCopyEx(m_renderer->get(), m_texture, NULL, &m_textRect, 0, NULL, SDL_FLIP_NONE);
}

void TextRenderer::setText(std::string text)
{
    if (text.length() < 1)
        throw std::runtime_error("Text cannot be empty");

    m_text = text;
    SDL_Surface *textSurface = TTF_RenderText_Blended_Wrapped(m_font, m_text.c_str(), m_color, 1000);
    // SDL_Surface *textSurface = TTF_RenderText_Solid(m_font, m_text.c_str(), m_color);
    
    if (textSurface == nullptr)
        throw std::runtime_error("Could not create surface from string");

    m_texture = SDL_CreateTextureFromSurface(m_renderer->get(), textSurface);
    SDL_FreeSurface(textSurface);

    if (m_texture == nullptr)
        throw std::runtime_error("Could not create texture from surface");

    auto width = textSurface->w;
    auto height = textSurface->h;

    auto [x, y] = calculatePosition(width, height);

    m_textRect = {(int)x, (int)y, width, height};
}

void TextRenderer::setTextColor(Color_T color)
{
    m_color.r = color.r;
    m_color.g = color.g;
    m_color.b = color.b;
    m_color.a = color.a;

    // Recreate if text has been set
    if (m_text.length() != 0)
        setText(m_text.c_str());
}

void TextRenderer::setLocation(TextLocation location)
{
    m_location = location;

    // Recreate if text has been set
    if (m_text.length() != 0)
        setText(m_text.c_str());
}

void TextRenderer::setBackground(uint16_t width, uint16_t height, Color_T color)
{
    auto [x, y] = calculatePosition(width, height);
    m_background.x = x;
    m_background.y = y;
    m_background.w = width;
    m_background.h = height;
    m_drawBackground = true;
    m_backgroundColor.r = color.r;
    m_backgroundColor.g = color.g;
    m_backgroundColor.b = color.b;
    m_backgroundColor.a = color.a;
}

void TextRenderer::drawBackground(bool on)
{
    m_drawBackground = on;
}

void TextRenderer::reposition()
{
    auto [x, y] = calculatePosition(m_background.w, m_background.h);
    m_background.x = x;
    m_background.y = y;
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
        x = (wWidth / 2) - (textWidth / 2);
        y = ((wHeight / 2) - (textHeight / 2));
        break;

    default:
        break;
    }
    return std::make_tuple(x, y);
}