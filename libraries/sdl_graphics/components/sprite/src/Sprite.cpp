#include "Sprite/Sprite.hpp"

#include <iostream>
#include <chrono>

using namespace sdl_graphics;

Sprite::Sprite(std::shared_ptr<Renderer> renderer, float sizePercentage)
    : m_renderer(renderer), m_sizePercentage(sizePercentage),
      m_currentSequence(0), m_currentIndex(0), m_xPosition(nullptr),
      m_yPosition(nullptr), m_angle(nullptr), m_interval(1)
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
    m_interval = (double) ms / 1000;
}

void Sprite::update()
{
    using namespace std::chrono;
    static auto timer = system_clock::now();

    std::chrono::duration<double> last_shift = system_clock::now() - timer;

    if (last_shift.count() < m_interval)
        return;
    
    timer = system_clock::now();
    std::cout << "Time: " << last_shift.count() << "\t\t" << m_interval << "\n";
    m_currentIndex++;
}

void Sprite::draw()
{
    if (m_sequences.size() < 1)
        return;
    
    if (m_currentIndex  >= m_sequences.at(m_currentSequence).size())
        m_currentIndex = 0;

    TilePosition_T pos;
    pos.x = m_xPosition != nullptr ? *m_xPosition : 0;
    pos.y = m_yPosition != nullptr ? *m_yPosition : 0;
    pos.a = m_angle != nullptr ? *m_angle : 0;
    m_sequences.at(m_currentSequence).at(m_currentIndex).draw(pos);
}