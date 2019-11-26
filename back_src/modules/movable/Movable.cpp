#include "Movable.hpp"

#include "Output.hpp"
#include "Settings.hpp"

#include <math.h>

Movable::Movable() {
    current_ = std::make_shared<position_t>();
    current_->x = WINDOW_WIDTH / 2;
    current_->y = WINDOW_HEIGHT / 2;
    current_->angle = 0;
}

void Movable::setPosition(int x, int y, int angle) {
    current_->x = x;
    current_->y = y;
    current_->angle = angle;
}

void Movable::moveForward(int velocity) {
    current_->x += sin(current_->angle * M_PI / 180) * velocity;
    current_->y -= cos(current_->angle * M_PI / 180) * velocity;
}

void Movable::moveBackward(int velocity) {
    current_->x -= sin(current_->angle * M_PI / 180) * velocity;
    current_->y += cos(current_->angle * M_PI / 180) * velocity;
}

void Movable::rotateRight(int velocity) {
    updateAngle(velocity);
}

void Movable::rotateLeft(int velocity) {
    updateAngle(-velocity);
}

const std::shared_ptr<position_t> Movable::getPosition() const {
    return current_;
}

std::string Movable::getPostitionString() const {
    std::stringstream ss;
    ss << "X: " << current_->x << ", Y: " << current_->y << ", A: " << current_->angle;
    return ss.str();
}

void Movable::updateAngle(int angle) {
    current_->angle += angle;
    if (current_->angle > 359) {
        current_->angle -= 360;
    }
    else if (current_->angle < 0) {
        current_->angle += 360;
    }
}