#ifndef SDL_IMAGE_INTERFACE_HPP
#define SDL_IMAGE_INTERFACE_HPP

namespace sdl_graphics
{

class SdlImage_I
{
public:
    virtual const std::string getImagePath() const = 0;
    virtual uint16_t getWidth() const = 0;
    virtual uint16_t getHeight() const = 0;
    virtual uint32_t getPosX() const = 0;
    virtual uint32_t getPosY() const = 0;
    virtual uint16_t getAngle() const = 0;

private:
};

} // namespace sdl_graphics

#endif // SDL_IMAGE_INTERFACE_HPP