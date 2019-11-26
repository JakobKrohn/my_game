#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <iostream>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"

#include "interfaces/IDrawable.hpp"

class Graphic {
public: 

    void addObject(IDrawable* object, std::string imagePath);

    bool begin(int x, int y);
    void update();

private: 

    SDL_Window * window_;
    SDL_Renderer * renderer_;

    std::vector<IDrawable*> objects_;

    SDL_Texture * loadTexture(std::string path);

};

#endif // GRAPHIC_H