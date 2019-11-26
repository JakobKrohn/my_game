#ifndef PLAYER_H
#define PLAYER_H

#include "interfaces/IDrawable.hpp"
#include "movable/Movable.hpp"

class Player : public Movable, public IDrawable {
public: 

    const char * const name_;

    Player(const char * name);

    const std::shared_ptr<const drawable_t> getDrawable() const;

    void initialize();

    void getData();

private: 

};

#endif // PLAYER_H