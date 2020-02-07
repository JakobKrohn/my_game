#include "Sprite/Sprite.hpp"

#include <chrono>
#include <type_traits>

#include "Logger/Logger.hpp"

using namespace components;

Sprite::Sprite(std::vector<std::shared_ptr<Drawable>> drawables)
    : m_drawables(drawables),
      m_state(sprite_state::IDLE), 
      m_sizeConstant(0)
{
    print("Sprite [", this, "] created __OLD__");
}

Sprite::Sprite(double sizeConstant)
    : m_state(sprite_state::IDLE), 
    m_sizeConstant(sizeConstant)
{
    print("Sprite [", this, "] created with size constant: ", sizeConstant);
    unsigned int index = static_cast<std::underlying_type<sprite_state>::type>(sprite_state::_END);
    m_assets.resize(index);
}

Sprite::~Sprite()
{
    print("Deleted");
}

std::vector<std::shared_ptr<Image_I>> Sprite::getAllImages()
{
    throw std::runtime_error("Wrong getter!");
    // TODO:  DO NOT CAST LIKE THIS!
    std::vector<std::shared_ptr<Image_I>> data;
    for (const auto &d : m_drawables)
    {
        data.push_back(d);
    }
    return data;
}

std::vector<const char *> Sprite::getAllAssets() const
{
    std::cout << "Get data\n";
    std::vector<const char*> all;
    all.reserve(1000); // todo: set size
    for (auto &asset : m_assets)
    {
        std::cout << "check mee\n";
        // std::copy(asset.begin(), asset.end(), all.data());
        std::copy(asset.begin(), asset.end(), std::back_inserter(all));
    }
    if (all.size() <= 0)
        std::cout << "error getting assets\n";
    std::cout << "return\n";
    return all;
}

double Sprite::getSizeConstant() const
{
    return m_sizeConstant;
}

uint Sprite::getCurrentIndex()
{
    std::cout << "Get current index\n";
    return 0;
    if (m_state == sprite_state::IDLE)
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

    m_state = sprite_state::IDLE;

    return (test ? 1 : 2);
}

void Sprite::setState(sprite_state state)
{
    m_state = state;
}

sprite_state Sprite::getState() const
{
    return m_state;
}

void Sprite::setIdleAssets(std::vector<const char *> &&assets)
{
    unsigned int index = static_cast<std::underlying_type<sprite_state>::type>(sprite_state::IDLE);
    setAssetsAt(index, std::move(assets));
    // m_idleAssets = assets;
}

void Sprite::setAttackAssets(std::vector<const char *> &&assets)
{
    unsigned int index = static_cast<std::underlying_type<sprite_state>::type>(sprite_state::ATTACK);
    setAssetsAt(index, std::move(assets));
    // m_attackAssets = assets;
}

void Sprite::setMovingAssets(std::vector<const char *> &&assets)
{
    unsigned int index = static_cast<std::underlying_type<sprite_state>::type>(sprite_state::MOVING);
    setAssetsAt(index, std::move(assets));
    // m_movingAssets = assets;
}

void Sprite::setReloadAssets(std::vector<const char *> &&assets)
{
    unsigned int index = static_cast<std::underlying_type<sprite_state>::type>(sprite_state::RELOAD);
    setAssetsAt(index, std::move(assets));
    // m_reloadAssets = assets;
}

void Sprite::setFiringAssets(std::vector<const char *> &&assets)
{
    unsigned int index = static_cast<std::underlying_type<sprite_state>::type>(sprite_state::FIRING);
    setAssetsAt(index, std::move(assets));
    // m_firingAssets = assets;
}

void Sprite::setAssetsAt(unsigned int index, std::vector<const char *> &&assets)
{
    m_assets.at(index) = assets;
}