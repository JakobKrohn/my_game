#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <memory>
#include <vector>
#include <map>

#include "SDL_image.h"

#include "Renderer/Renderer.hpp"
#include "SdlGraphics/SdlImage_I.hpp"
#include "SdlGraphics/SdlElement_I.hpp"

namespace sdl_graphics
{

class Image
{
public:
    Image(std::shared_ptr<Renderer> renderer, std::shared_ptr<SdlImage_I> drawable);
    Image(std::shared_ptr<Renderer> renderer, std::vector<std::shared_ptr<SdlImage_I>> images);
    Image(std::shared_ptr<Renderer> renderer, std::shared_ptr<SdlElement_I> element);

    // TODO destruct

    void draw();

private:
    std::shared_ptr<Renderer> m_renderer;
    std::shared_ptr<SdlImage_I> m_drawable;
    std::shared_ptr<SdlElement_I> m_element;
    std::vector<SDL_Texture*> m_textures;
    // std::map<std::shared_ptr<SdlImage_I>, SDL_Texture*> m_drawables;
    // std::vector<std::shared_ptr<SdlImage_I>> m_textures;
    SDL_Texture *m_texture;
    SDL_Rect m_rect;
};

} // namespace sdl_graphics

#endif // IMAGE_HPP