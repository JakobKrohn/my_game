#ifndef SDL_GRAPHICS_HPP
#define SDL_GRAPHICS_HPP

#include <vector>
#include <memory>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "SdlImage_I.hpp"
#include "Graphics_I.hpp"
#include "SdlElement_I.hpp"

#include "Window/Window.hpp"
#include "Renderer/Renderer.hpp"
#include "Image/Image.hpp"
#include "TextRenderer/TextRenderer.hpp"

namespace sdl_graphics
{

class SdlGraphics : public Graphics_I
{
public:
    SdlGraphics(unsigned int windowPositionX = 0, unsigned int windowPositionY = 0);

    void update();
    void addElement(std::shared_ptr<SdlImage_I> element);
    void addElement(std::shared_ptr<SdlElement_I> element);

private:
    std::shared_ptr<Window> m_window;
    std::shared_ptr<Renderer> m_renderer;
    std::unique_ptr<TextRenderer> m_fpsRenderer;
    std::vector<Image> m_elements;
    // std::vector<std::pair<std::shared_ptr<SdlImage_I>, Image>> m_elements;
    uint32_t m_countedFrames;
    TTF_Font *m_font;

    double getFramesPerSecond(uint32_t startTime);
    void drawFrame(int width, int height) const;
    static int resizeEvent(void *data, SDL_Event *event); // todo: not static
};

} // namespace sdl_graphics

#endif // SDL_GRAPHICS_HPP
