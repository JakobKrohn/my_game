#include "Sprite/Sprite2.hpp"

#include <iostream>

using namespace sdl_graphics;

Sprite::Sprite(std::shared_ptr<Renderer> renderer, float sizePercentage)
    : m_renderer(renderer), m_sizePercentage(sizePercentage),
      m_currentSequence(0), m_currentIndex(0), m_xPosition(nullptr),
      m_yPosition(nullptr), m_angle(nullptr), m_interval(0)
{
}

Sprite::~Sprite()
{
}

unsigned int Sprite::addSequence(std::vector<const char *> assets)
{
    m_sequences.emplace_back(std::vector<Tile>());
    for (const auto &asset : assets)
    {
        m_sequences.back().emplace_back(
            Tile(m_renderer, asset, m_sizePercentage));
    }
    return m_sequences.size() - 1;
}

void Sprite::setCurrentSequence(unsigned int sequence)
{
    m_currentSequence = sequence;
}

void Sprite::setPosition(std::shared_ptr<float> x, std::shared_ptr<float> y,
                         std::shared_ptr<float> a)
{
    m_xPosition = x;
    m_yPosition = y;
    m_angle = a;
}

void Sprite::setTimeInterval(int ms, int sequence)
{
    std::cout << "WARNING: Multiple time intervals is not implemented!\n";
    m_interval = ms;
}

void Sprite::update()
{
}

void Sprite::draw()
{
    if (m_sequences.size() < 1)
        return;
    
    if (m_currentIndex + 1 >= m_sequences.at(m_currentSequence).size())
        m_currentIndex = 0;

    TilePosition_T pos;
    pos.x = m_xPosition != nullptr ? *m_xPosition : 0;
    pos.y = m_yPosition != nullptr ? *m_yPosition : 0;
    pos.a = m_angle != nullptr ? *m_angle : 0;
    m_sequences.at(m_currentSequence).at(m_currentIndex).draw(pos);
}