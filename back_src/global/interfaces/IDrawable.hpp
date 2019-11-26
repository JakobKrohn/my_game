#ifndef I_DRAWABLE_HPP
#define I_DRAWABLE_HPP

#include <memory>

struct drawable_t {
    int x;
    int y;
    int angle;
    int width;
    int height;
};

class IDrawable {
public: 

    IDrawable() {
        drawData = std::make_shared<drawable_t>();
    }

    virtual const std::shared_ptr<const drawable_t> getDrawable() const = 0;
        // std::shared_ptr<const drawable_t> getDrawable() const;

protected: 

    std::shared_ptr<drawable_t> drawData;

private: 
};

#endif // I_DRAWABLE_HPP