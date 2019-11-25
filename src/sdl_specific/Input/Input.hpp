#ifndef INPUT_H
#define INPUT_H

#include <functional>
#include <map>

#include <SDL.h>

class Input {
public: 

    static Input& getInstance() {
        static Input instance;
        return instance;
    }

    Input(Input const&) = delete;
    void operator=(Input const&) = delete;

    uint8_t registerCallback(std::function<void()> cb, SDL_Keycode key);

    void setExitCallback(std::function<void()> cb);
    void check();
    
private: 
    Input(){}
    SDL_Event event_;
    std::function<void()> exitCallback_;
    std::map<SDL_Keycode, std::function<void()>> callbacks_;

    bool isExitEvent(SDL_Event event);
    void printKeyInfo(SDL_KeyboardEvent * key);

};

#endif // INPUT_H


// https://stackoverflow.com/questions/1008019/c-singleton-design-pattern