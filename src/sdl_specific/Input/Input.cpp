#include "Input.hpp"

#include <exception>
#include <iostream>

#include "Output.hpp"

uint8_t Input::registerCallback(std::function<void()> cb, SDL_Keycode key) {
    callbacks_.emplace(std::make_pair(key, cb));
    return 0;
}

void Input::setExitCallback(std::function<void()> cb) {
    exitCallback_ = cb;
}

void Input::check() {
    while (SDL_PollEvent(&event_)) {
        if (event_.type == SDL_KEYDOWN) {
            printKeyInfo(&event_.key);
            
            auto it = callbacks_.find(event_.key.keysym.sym);
            if (it != callbacks_.end()) {
                it->second();
            }
        }
        if (isExitEvent(event_)) {
            try {
                exitCallback_();
            } catch (std::exception& e) {
                print("Callback excepetion: " + std::string("") + std::string(e.what()));
            }
        }
    }
}

bool Input::isExitEvent(SDL_Event event) {
    if (event.type != SDL_KEYDOWN) {
        return false;
    }
    if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
        return true;
    }
    return false;
}

void Input::printKeyInfo(SDL_KeyboardEvent * key) {
    print(SDL_GetKeyName(key->keysym.sym));
    // if (key->type == SDL_KEYUP) {
    //     print("Release -> ");
    // }
    // else {
    //     std::cout << "Press -> ";
    // }

    // std::cout << "0x" << key->keysym.scancode;
    // std::cout << ", name: " << SDL_GetKeyName(key->keysym.sym) << std::endl;
}