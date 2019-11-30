#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Player_I.hpp"

#include "Movable/Movable_I.hpp"

namespace component
{
class Player
{
public:
    const char *const name_;

    Player(const char *name);

    void initialize();

    void getData();

private:
};
} // namespace component

#endif // PLAYER_H