#include "Sprite/Sprite.hpp"

#include <chrono>
#include <iostream>

using namespace sdl_graphics;

Sprite::Sprite(std::shared_ptr<Renderer> renderer, float sizePercentage)
    : m_renderer(renderer), m_sizePercentage(sizePercentage),
      m_currentSequence(0), m_previousSequence(0), m_currentIndex(0),
      m_xPosition(nullptr), m_yPosition(nullptr), m_angle(nullptr),
      m_interval(1), m_angleOffset(0)
{
}

Sprite::~Sprite()
{
}

void Sprite::update()
{
    using namespace std::chrono;
    static auto timer = system_clock::now();

    std::chrono::duration<double> last_shift = system_clock::now() - timer;

    if (last_shift.count() < m_intervals.at(m_currentSequence))
        return;

    timer = system_clock::now();
    // std::cout << "Time: " << last_shift.count() << "\t\t"
    //           << m_intervals.at(m_currentSequence) << "\n";
    m_currentIndex++;
}

void Sprite::draw()
{
    if (m_sequences.size() < 1)
        return;

    if (m_currentIndex >= m_sequences.at(m_currentSequence).size())
    {
        if (m_oneRuns.at(m_currentSequence))
        {
            m_currentSequence = m_previousSequence;
            m_currentIndex = 0;
        }
        else
            m_currentIndex = 0;
    }

    TilePosition_T pos;
    pos.x = m_xPosition != nullptr ? *m_xPosition : 0;
    pos.y = m_yPosition != nullptr ? *m_yPosition : 0;
    pos.a = m_angle != nullptr ? *m_angle : 0;
    pos.a += m_angleOffset;
    m_sequences.at(m_currentSequence).at(m_currentIndex).draw(pos);
}

unsigned int Sprite::addSequence(std::vector<const char *> assets, int ms,
                                 bool oneRun)
{
    m_intervals.push_back(m_interval);
    m_oneRuns.push_back(oneRun);
    m_sequences.emplace_back(std::vector<Tile>());
    for (const auto &asset : assets)
        m_sequences.back().emplace_back(
            Tile(m_renderer, asset, m_sizePercentage));
    setTimeInterval(ms, m_sequences.size() - 1);
    return m_sequences.size() - 1;
}

void Sprite::setCurrentSequence(unsigned int sequence)
{
    if (m_currentSequence == sequence)
        return;

    if (m_oneRuns.at(m_currentSequence))
        return;

    m_previousSequence = m_currentSequence;
    m_currentSequence = sequence;
    m_currentIndex = 0;
}

void Sprite::setPosition(std::shared_ptr<float> x, std::shared_ptr<float> y,
                         std::shared_ptr<float> a)
{
    m_xPosition = x;
    m_yPosition = y;
    m_angle = a;
}

void Sprite::setAngleOffset(int angle)
{
    m_angleOffset = angle;
}

void Sprite::setSizePercentage(float sizePercentage)
{
    m_sizePercentage = sizePercentage;
}

void Sprite::setTimeInterval(int ms, int sequence)
{
    double interval = (double)ms / 1000;
    if (sequence < 0)
    {
        m_interval = interval;
        for (uint i = 0; i < m_intervals.size(); i++)
            m_intervals.at(i) = interval;
        return;
    }

    if ((unsigned)sequence > m_intervals.size())
        std::cout << "\tTime interval not fitting in vector!!!\n";

    m_intervals.at(sequence) = interval;
}
