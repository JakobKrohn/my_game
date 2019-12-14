#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <memory>

#include "SDL_image.h"

#include "Renderer/Renderer.hpp"
#include "Graphics/Drawable.hpp"

namespace sdl_graphics
{
class Image
{
public:
    Image(std::shared_ptr<Renderer> renderer, std::shared_ptr<graphics::Drawable> drawable);
    // TODO destruct

    void draw();

private:
    std::shared_ptr<Renderer> m_renderer;
    std::shared_ptr<graphics::Drawable> m_drawable;
    SDL_Texture *m_texture;
    SDL_Rect m_rect;
};
} // namespace sdl_graphics

#endif // IMAGE_HPP