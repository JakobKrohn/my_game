#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Player_I.hpp"

#include "Movable/Movable_I.hpp"
#include "Movable/Movable.hpp"
#include "Graphics/Drawable_I.hpp"
#include "Graphics/Drawable.hpp"

namespace components
{

class Player : public Movable, public Player_I
{
public:
    const char *const name_;

    Player(const char *name, graphics::Drawable_T drawData);

private:
};

} // namespace components

#endif // PLAYER_H