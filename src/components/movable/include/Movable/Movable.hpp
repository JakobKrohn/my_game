#ifndef COMPONENTS_MOVABLE_HPP
#define COMPONENTS_MOVABLE_HPP

#include "Movable_I.hpp"

#include <memory>
#include <vector>

#include "Logger/Logger.hpp"

namespace components
{

class Movable : public Movable_I
{
  public:
    Movable();
    Movable(const Movable &) = delete;
    ~Movable();

    bool isMoving() const;

    void setBoundaries(Rectangle_T boundaries);
    void setPosition(uint32_t x, uint32_t y, uint16_t angle);
    const std::shared_ptr<Position_T> getPosition() const;

    void move(int velocity);
    void rotate(int velocity);

  protected:
  private:
    std::shared_ptr<Position_T> m_position;
    Rectangle_T m_boundaries;

    void updateAngle(int angle);
    bool isInsideBoundaries(int x, int y) const;
    void handleBoundaries();
};

} // namespace components

#endif // COMPONENTS_MOVABLE_HPP