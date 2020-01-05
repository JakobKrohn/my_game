#ifndef SDL_GRAPHICS_HPP
#define SDL_GRAPHICS_HPP

#include <vector>
#include <memory>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "GraphicsInterface/Graphics_I.hpp"
#include "Window/Window.hpp"
#include "Renderer/Renderer.hpp"
#include "Image/Image.hpp"
#include "TextRenderer/TextRenderer.hpp"
#include "Element/Element.hpp"

namespace sdl_graphics
{

class SdlGraphics : public Graphics_I
{
public:
    explicit SdlGraphics(unsigned int windowPositionX = 0, unsigned int windowPositionY = 0);
    ~SdlGraphics();

    // Graphics_I
    void update();
    void addElement(std::shared_ptr<Element_I> element);
    void addImage(std::shared_ptr<Image_I> image);
    std::shared_ptr<Text_I> createText(const char * fontPath, uint8_t fontSize);
    std::shared_ptr<uint32_t> getWindowWidth() const;
    std::shared_ptr<uint32_t> getWindowHeight() const;

private:
    std::shared_ptr<Window> m_window;
    std::shared_ptr<Renderer> m_renderer;
    std::unique_ptr<TextRenderer> m_fpsRenderer;
    std::vector<Element> m_elements;
    std::vector<Image> m_images;
    std::vector<std::shared_ptr<TextRenderer>> m_textElements;
    std::shared_ptr<uint32_t> m_windowWidth;
    std::shared_ptr<uint32_t> m_windowHeight;
    uint32_t m_countedFrames;

    double getFramesPerSecond(uint32_t startTime);
    void drawFPS(double fps);
    void drawFrame(int width, int height) const;
    static int windowEvent(void *data, SDL_Event *event); 
    void redrawAll();
};

} // namespace sdl_graphics

#endif // SDL_GRAPHICS_HPP
