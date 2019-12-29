#include "Sprite/Sprite.hpp"

#include <chrono>

#include "Logger/Logger.hpp"

using namespace components;

Sprite::Sprite(std::vector<std::shared_ptr<Drawable>> drawables) : m_drawables(drawables), m_state(sprite_state::STILL)
{
}

Sprite::~Sprite()
{
    print("Deleted");
}

std::vector<std::shared_ptr<Image_I>> Sprite::getAllImages()
{
    // DO NOT CAST LIKE THIS!
    std::vector<std::shared_ptr<Image_I>> data;
    for (const auto &d : m_drawables)
    {
        data.push_back(d);
    }
    return data;
}

std::shared_ptr<Image_I> Sprite::getCurrentImage()
{
}

uint Sprite::getCurrentIndex()
{
    if (m_state == sprite_state::STILL)
    {
        return 0;
    }
    static bool test = 0;
    static auto t = std::chrono::high_resolution_clock::now();
    auto n = std::chrono::high_resolution_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(n - t).count() > 250)
    {
        t = std::chrono::high_resolution_clock::now();
        test = !test;
    }

    m_state = sprite_state::STILL;

    return (test ? 1 : 2);
}

void Sprite::setState(sprite_state state)
{
    m_state = state;
}