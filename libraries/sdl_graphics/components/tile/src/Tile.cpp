#include "Tile/Tile.hpp"

#include "Logger/Logger.hpp"

using namespace sdl_graphics;

Tile::Tile(std::shared_ptr<Renderer> renderer, const char *imagePath)
    : m_width(0),
      m_height(0),
      m_texture(nullptr)
{
    m_texture = std::make_shared<Texture>(renderer, imagePath);

    m_width = m_texture->getWidth();
    m_height = m_texture->getHeight();

    print("Tile '", this, "' created.", "\n\tPath: ", imagePath, " \n\tWidth: ", m_width, ", height: ", m_height);
}

Tile::~Tile()
{
    print("Tile '", this, "' destroyed");
}