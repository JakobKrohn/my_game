#ifndef SDL_SPRITE_HPP
#define SDL_SPRITE_HPP

#include "GraphicsInterface/Sprite_I.hpp"

namespace sdl_graphics
{

class Sprite : public Sprite_I
{
  public:
    Sprite(float sizePercentage);
    ~Sprite();

    // Sprite_I
    unsigned int addSequence(std::vector<const char *> assets);
    void setCurrentSequence(unsigned int sequence);
    void setPosition(std::shared_ptr<float> x, std::shared_ptr<float> y,
                     std::shared_ptr<float> a);

  private:
};

} // namespace sdl_graphics

#endif // SDL_SPRITE_HPP