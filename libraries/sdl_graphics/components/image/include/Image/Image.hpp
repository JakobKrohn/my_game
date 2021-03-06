#ifndef SDL_IMAGE_HPP
#define SDL_IMAGE_HPP

#include <memory>

#include "SDL_image.h"

#include "GraphicsInterface/Image_I.hpp"
#include "Renderer/Renderer.hpp"

namespace sdl_graphics
{

class Image
{
  public:
    Image(std::shared_ptr<Renderer> renderer,
          std::shared_ptr<Image_I> drawable);
    Image(const Image &); // Copy constructor
    ~Image();

    void draw();

  private:
    std::shared_ptr<Renderer> m_renderer;
    std::shared_ptr<Image_I> m_drawable;
    SDL_Texture *m_texture;
    SDL_Rect m_rect;
};

} // namespace sdl_graphics

#endif // SDL_IMAGE_HPP