#ifndef SDL_ELEMENT_HPP
#define SDL_ELEMENT_HPP

#include <memory>
#include <vector>

#include "GraphicsInterface/Element_I.hpp"
#include "Image/Image.hpp"
#include "Renderer/Renderer.hpp"

namespace sdl_graphics
{

/**
 *  A new name to Element or Element_I????
 */
class Element
{
  public:
    Element(std::shared_ptr<Renderer> renderer,
            std::shared_ptr<Element_I> element);
    void draw();

  private:
    std::shared_ptr<Element_I> m_element;
    std::shared_ptr<Renderer> m_renderer;
    std::vector<Image> m_images;
};

} // namespace sdl_graphics

#endif // SDL_ELEMENT_HPP