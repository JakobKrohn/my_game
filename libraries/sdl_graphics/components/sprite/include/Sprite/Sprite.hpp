#ifndef SDL_SPRITE_HPP
#define SDL_SPRITE_HPP

#include <memory>
#include <vector>

#include "GraphicsInterface/Sprite_I.hpp"
#include "Renderer/Renderer.hpp"
#include "Tile/Tile.hpp"

namespace sdl_graphics
{

class Sprite : public Sprite_I
{
  public:
    Sprite(std::shared_ptr<Renderer> renderer, float sizePercentage);
    ~Sprite();

    void update();
    void draw();

    // Sprite_I
    unsigned int addSequence(std::vector<const char *> assets,
                             bool oneRun = false);
    void setCurrentSequence(unsigned int sequence);
    void setPosition(std::shared_ptr<float> x, std::shared_ptr<float> y,
                     std::shared_ptr<float> a);
    void setTimeInterval(int ms, int sequence = -1);
    void setAngleOffset(int angle);
    void setSizePercentage(float sizePercentage);

  private:
    std::shared_ptr<Renderer> m_renderer;
    float m_sizePercentage;
    std::vector<std::vector<Tile>> m_sequences;
    unsigned int m_currentSequence;
    unsigned int m_previousSequence;
    unsigned int m_currentIndex;
    std::shared_ptr<float> m_xPosition;
    std::shared_ptr<float> m_yPosition;
    std::shared_ptr<float> m_angle;
    double m_interval;
    int m_angleOffset;
    std::vector<double> m_intervals;
    std::vector<bool> m_oneRuns;
};

} // namespace sdl_graphics

#endif // SDL_SPRITE_HPP