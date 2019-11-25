#include <iostream>

#include "BoxHead.hpp"

int main(int argc, char **argv) {
    BoxHead boxHead;
    if (argc > 1) {
        std::cout << argv[2] << "\n";
        boxHead.begin(1);
    }
    else {
        boxHead.begin(0);
    }
    return 0;
}
