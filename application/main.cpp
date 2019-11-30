#include <iostream>

#include "Movable/Movable.hpp"
#include "Player/Player.hpp"

#include "GameEngine/GameEngine.hpp"

int main(int argc, char **argv) {
    component::Player player("name");
    component::Movable movable;
    
    if (argc > 1) {
        std::cout << argv[2] << "\n";
    }
    else {
    }
    return 0;
}
