#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Player_I.hpp"

#include <vector>

#include "Movable/Movable_I.hpp"
#include "Movable/Movable.hpp"
#include "Graphics/Drawable_I.hpp"
#include "Graphics/Drawable.hpp"

namespace components
{

class Player : public Movable, public Player_I
{
public:
    const char *const m_name;

    Player(const char *name, graphics::Image_T drawData);
    Player(const char *name, std::vector<graphics::Image_T> imageData);

private:
};

} // namespace components

#endif // PLAYER_H