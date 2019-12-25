#include "Element/Element.hpp"

using namespace sdl_graphics;

Element::Element(std::shared_ptr<Renderer> renderer, std::shared_ptr<Element_I> element)
{
    m_element = element;
    m_renderer = renderer;
    auto images = element->getAllImages();
    for (const auto & img : images)
    {
        m_images.emplace_back(m_renderer, img);
    }
}

void Element::draw()
{
    m_images.at(m_element->getCurrentIndex()).draw();
}