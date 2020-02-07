#include "Element/Element.hpp"

#include <iostream>

using namespace sdl_graphics;

Element::Element(std::shared_ptr<Renderer> renderer, std::shared_ptr<Element_I> element)
{
    m_element = element;
    m_renderer = renderer;
    // auto images = element->getAllImages();
    auto images = element->getAllAssets();
    for (const auto & img : images)
    {
        std::cout << "adding image\n";
        m_images.emplace_back(m_renderer, img);
    }
}

void Element::draw()
{
    if (m_images.size() <= 0)
    {
        std::cout << "m_images empty\n";
        return;
    }
    SDL_Rect r {50, 50, 50, 50};
    std::cout << "check\n";
    m_images.at(m_element->getCurrentIndex()).draw(r, r);
    std::cout << "Draw done\n";
    // m_images.at(m_element->getCurrentIndex()).draw();
}