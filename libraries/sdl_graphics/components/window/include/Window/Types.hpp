#ifndef WINDOW_TYPES_HPP
#define WINDOW_TYPES_HPP

#include <stdint.h>

namespace sdl_graphics
{
    
struct WindowPosition
{
    uint16_t x_begin;
    uint16_t y_begin;
    uint16_t x_end;
    uint16_t y_end;
};

struct WindowSize
{
    uint16_t width;
    uint16_t height;
};

} // namespace sdl_graphics


#endif // WINDOW_TYPES_HPP