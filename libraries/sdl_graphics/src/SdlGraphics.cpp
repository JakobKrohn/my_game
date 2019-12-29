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

    m_renderer = std::make_shared<Renderer>(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

    m_windowWidth = std::make_shared<uint32_t>(0);
    m_windowHeight = std::make_shared<uint32_t>(0);

    SDL_Color textColor = {0, 0, 0, 255};
    m_fpsRenderer = std::make_unique<TextRenderer>(2, 0, textColor, m_renderer);

    SDL_AddEventWatch(resizeEvent, m_window->get());

    // Clear the window
    m_renderer->setColor(0x00, 0x00, 0x00);
    m_renderer->clear();
    m_renderer->present();
}

void SdlGraphics::update()
{
    static auto start = SDL_GetTicks();

    m_renderer->setColor(0xFF, 0xFF, 0x00);
    m_renderer->clear();

    auto [width, height] = m_renderer->getWindowSize();
    *m_windowWidth = width;
    *m_windowHeight = height;

    m_renderer->setColor(0x00, 0x00, 0xFF);
    drawFrame(width, height);

    for (auto &image : m_images)
    {
        image.draw();
    }

    for (auto &element : m_elements)
    {
        element.draw();
    }

    auto fps = getFramesPerSecond(start);
    m_fpsRenderer->renderText(std::to_string(fps));

    m_renderer->present();
}

void SdlGraphics::addElement(std::shared_ptr<Element_I> element)
{
    m_elements.emplace_back(m_renderer, element);
}

void SdlGraphics::addImage(std::shared_ptr<Image_I> image)
{
    m_images.emplace_back(m_renderer, image);
}

std::shared_ptr<uint32_t> SdlGraphics::getWindowWidth() const
{
    return m_windowWidth;
}

std::shared_ptr<uint32_t> SdlGraphics::getWindowHeight() const
{
    return m_windowHeight;
}

double SdlGraphics::getFramesPerSecond(uint32_t startTime)
{
    auto stop = SDL_GetTicks();
    double averageFPS = m_countedFrames / ((stop - startTime) / 1000.f);
    if (averageFPS > 2000000)
    {
        averageFPS = 0;
    }
    m_countedFrames++;
    return averageFPS;
}

void SdlGraphics::drawFrame(int width, int height) const
{
    // SDL_RenderSetScale(m_renderer->get(), 5, 5);
    SDL_RenderDrawLine(m_renderer->get(), 0, 0, width, 0);                   // top
    SDL_RenderDrawLine(m_renderer->get(), 0, 0, 0, height);                  // left
    SDL_RenderDrawLine(m_renderer->get(), width - 1, 0, width - 1, height);  // right
    SDL_RenderDrawLine(m_renderer->get(), 0, height - 1, width, height - 1); // bottom
    // SDL_RenderSetScale(m_renderer->get(), 1, 1);
}

int SdlGraphics::resizeEvent(void *data, SDL_Event *event)
{
    if (event->type == SDL_WINDOWEVENT && event->window.event == SDL_WINDOWEVENT_RESIZED)
    {
        SDL_Window *win = SDL_GetWindowFromID(event->window.windowID);
        if (win == (SDL_Window *)data)
        {
            printf("resizing.....\n");
        }
    }
    return 0;
}