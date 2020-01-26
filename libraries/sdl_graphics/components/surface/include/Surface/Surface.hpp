#ifndef SDL_SURFACE_HPP
#define SDL_SURFACE_HPP

#include "SDL_image.h"

namespace sdl_graphics
{

class Surface
{
public:
    Surface(const char *imagePath);
    ~Surface();

    SDL_Surface *get() const;

    // Get size width, height
    void getSize(unsigned int &width, unsigned int &height);

private:
    SDL_Surface *m_surface;

    unsigned int m_width;
    unsigned int m_height;
};

} // namespace sdl_graphics

#endif // SDL_SURFACE_HPP