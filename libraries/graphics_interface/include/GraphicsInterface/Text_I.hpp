#ifndef GRAPHICS_INTERFACE_TEXT_HPP
#define GRAPHICS_INTERFACE_TEXT_HPP

#include <iostream>
#include <stdint.h>
#include <string>

enum class TextLocation
{
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT,
    FLOATING
};

struct Color_T
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

/**
 * Interface for text rendering
 */
class Text_I
{
  public:
    virtual ~Text_I()
    {
    }

    virtual void draw() = 0;

    // Set text
    virtual void setText(std::string text) = 0;

    // Set color for text
    virtual void setTextColor(Color_T color) = 0;

    // Set the location for text
    virtual void setLocation(TextLocation location) = 0;

    // Turn background on/off
    virtual void drawBackground(bool mode) = 0;

    // Set the text background size and color
    virtual void setBackground(uint16_t width, uint16_t height,
                               Color_T color) = 0;
};

#endif // GRAPHICS_INTERFACE_TEXT_HPP