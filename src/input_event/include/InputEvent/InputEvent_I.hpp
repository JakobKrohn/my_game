#ifndef INPUT_EVENT_INTERFACE_HPP
#define INPUT_EVENT_INTERFACE_HPP

#include <functional>

namespace input_event
{

enum class input_key
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    SPACE,
    ESCAPE,
    SHIFT,
    Q,
    W,
    E,
    R,
    T,
    Y,
    U,
    I,
    O,
    P,
    A,
    S,
    D,
    F,
    G,
    H,
    J,
    K,
    L,
    Z,
    X,
    C,
    V,
    B,
    N,
    M
};

class InputEvent_I
{
public:
    virtual void registerCallback(std::function<void()> callback, input_event::input_key key) = 0;
    virtual void setExitCallback(std::function<void()> callback) = 0;

    virtual void check() = 0;

private:
};
} // namespace input_event

#endif // INPUT_EVENT_INTERFACE_HPP