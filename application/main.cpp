#include <iostream>

#include "Movable/Movable.hpp"
#include "Player/Player.hpp"

#include "GameEngine/GameEngine.hpp"
// #include "GameEngine.hpp"

int main(int argc, char **argv) {
    Player player("name");
    Movable movable;
    
    if (argc > 1) {
        std::cout << argv[2] << "\n";
    }
    else {
    }
    return 0;
}
