#include "SdlGraphics/SdlGraphics.hpp"

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

SdlGraphics::SdlGraphics(unsigned int windowPosX, unsigned int windowPosY) : m_countedFrames(0)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        throw std::runtime_error(IMG_GetError());
    }

    if (TTF_Init() == -1)
    {
        throw std::runtime_error(TTF_GetError());
    }

    m_window = std::make_shared<Window>(windowPosX, windowPosY, 640, 580, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    // m_renderer = std::make_shared<Renderer>(m_window, -1, SDL_RENDERER_ACCELERATED);
    m_renderer = std::make_shared<Renderer>(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

    m_font = TTF_OpenFont("assets/fonts/OpenSans-Light.ttf", 20);
    if (m_font == NULL)
    {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
    }

    // Clear the window
    m_renderer->setColor(0x00, 0x00, 0x00);
    m_renderer->clear();
    m_renderer->present();

    // Draw frame
    m_renderer->setColor(0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(m_renderer->get(), 0, 50, 500, 550);
    m_renderer->present();
}

void SdlGraphics::update()
{
    static auto start = SDL_GetTicks();

    m_renderer->setColor(0x00, 0x00, 0x00);
    m_renderer->clear();

    // Draw frame
    // m_renderer->setColor(0xFF, 0xFF, 0xFF);
    // SDL_RenderDrawLine(m_renderer->getSdlObject(), 0, 50, 500, 550);

    for (auto &element : m_elements)
    {
        element.second.draw();
    }

    // ==================================================================
    auto stop = SDL_GetTicks();
    double averageFPS = m_countedFrames / ((stop - start) / 1000.f);
    if (averageFPS > 2000000)
    {
        averageFPS = 0;
    }
    m_countedFrames++;
    std::stringstream fps;
    fps.str("");
    fps << averageFPS;

    SDL_Color textColor = {255, 255, 0, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(m_font, fps.str().c_str(), textColor);
    if (textSurface != NULL)
    {
        auto texture = SDL_CreateTextureFromSurface(m_renderer->get(), textSurface);
        if (texture == NULL)
        {
            throw std::runtime_error("Could not create texture from surface");
        }

        auto mWidth = textSurface->w;
        auto mHeight = textSurface->h;

        SDL_Rect renderQuad = {0, 0, mWidth, mHeight};

        SDL_FreeSurface(textSurface);
        SDL_RenderCopyEx(m_renderer->get(), texture, NULL, &renderQuad, 0, NULL, SDL_FLIP_NONE);
    }
    // ==================================================================

    m_renderer->present();
}

void SdlGraphics::addElement(std::shared_ptr<graphics::Drawable_I> element)
{
    Image image(m_renderer, element);
    m_elements.push_back(std::make_pair(element, image));
}
