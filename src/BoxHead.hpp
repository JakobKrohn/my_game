#ifndef BOX_HEAD_H
#define BOX_HEAD_H

#include "modules/movable/player/Player.hpp"
#include "sdl_specific/Graphic/Graphic.hpp"
#include "sdl_specific/Input/Input.hpp"

#include <map>
#include <vector>

class BoxHead {
public: 
    BoxHead();
    void begin(int flag);
private: 
    Graphic graphic_;

    std::vector<Player> players_;

    bool isRunning_;
    
    bool initialize();
    void start();
    void quit();
};

#endif // BOX_HEAD_H