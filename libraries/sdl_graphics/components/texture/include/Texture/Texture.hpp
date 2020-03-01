#ifndef SDL_TEXTURE_HPP
#define SDL_TEXTURE_HPP

#include <memory>

#include "SDL.h"

#include "Renderer/Renderer.hpp"
#include "Window/Window.hpp"
#include "Surface/Surface.hpp"

namespace sdl_graphics
{

class Texture
{
  public:
    Texture(std::shared_ptr<Renderer> renderer, const char *imagePath);
    ~Texture();

    SDL_Texture *get() const;

    const unsigned int &getWidth() const;
    const unsigned int &getHeight() const;

  private:
    SDL_Texture *m_texture;

    unsigned int m_width;
    unsigned int m_height;
};

} // namespace sdl_graphics

#endif // SDL_TEXTURE_HPP