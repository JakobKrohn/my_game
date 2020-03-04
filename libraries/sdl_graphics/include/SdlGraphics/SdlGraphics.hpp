#ifndef SDL_GRAPHICS_HPP
#define SDL_GRAPHICS_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Element/Element.hpp"
#include "GraphicsInterface/Graphics_I.hpp"
#include "Image/Image.hpp"
#include "Renderer/Renderer.hpp"
#include "Sprite/Sprite2.hpp"
#include "TextRenderer/TextRenderer.hpp"
#include "TileMap/TileMap.hpp"
#include "Window/Window.hpp"

namespace sdl_graphics
{

class SdlGraphics : public Graphics_I
{
  public:
    explicit SdlGraphics(unsigned int windowPositionX = 0,
                         unsigned int windowPositionY = 0);
    ~SdlGraphics();

    // Graphics_I
    void update();
    void addElement(std::shared_ptr<Element_I> element);
    void addImage(std::shared_ptr<Image_I> image);
    std::shared_ptr<TileMap_I> createTileMap(const char *imagePath, float size);
    std::shared_ptr<Sprite_I> createSprite(float sizePercentage = -1);
    std::shared_ptr<Text_I> createText(const char *fontPath, uint8_t fontSize);
    std::shared_ptr<uint32_t> getWindowWidth() const;
    std::shared_ptr<uint32_t> getWindowHeight() const;
    void setResizeEventCallback(
        std::function<void(uint32_t width, uint32_t height)> callback);

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
    std::function<void(uint32_t width, uint32_t height)> m_resizeCallback;
    std::shared_ptr<TileMap> m_background;
    std::vector<std::shared_ptr<Sprite>> m_sprites;

    double getFramesPerSecond(uint32_t startTime);
    void drawFPS(double fps);
    void drawFrame(int width, int height) const;
    static int windowEvent(void *data, SDL_Event *event);
    void redrawAll();
};

} // namespace sdl_graphics

#endif // SDL_GRAPHICS_HPP
