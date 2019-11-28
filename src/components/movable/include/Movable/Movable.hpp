#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include <memory>

struct position_t {
    int x;
    int y;
    int angle;
};

class Movable {
public: 

    Movable();

    void setPosition(int x, int y, int angle);

    void moveForward(int velocity);
    void moveBackward(int velocity);
    void rotateLeft(int velocity);
    void rotateRight(int velocity);

    const std::shared_ptr<position_t> getPosition() const;

protected: 

private: 

    std::shared_ptr<position_t> current_;

    void updateAngle(int angle);

};

#endif // MOVABLE_HPP