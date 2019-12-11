#include "SdlGraphics/SdlGraphics.hpp"

using namespace sdl_graphics;

void SdlGraphics::createWindow(unsigned int windowPosX, unsigned int windowPosY)
{
    
}

void SdlGraphics::update()
{

}

void SdlGraphics::addElement(std::shared_ptr<graphics::Drawable_I> element)
{
    m_elements.push_back(element);
}