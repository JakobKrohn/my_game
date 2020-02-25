#include "doctest/doctest.h"

#include "Settings.hpp"
#include "src/modules/movable/Movable.hpp"

#include <math.h>

TEST_CASE("Starts inside window")
{
    Movable m;
    auto pos = m.getPosition();

    CHECK(pos->x > 0);
    CHECK(pos->y > 0);

    CHECK(pos->x <= WINDOW_WIDTH);
    CHECK(pos->y <= WINDOW_HEIGHT);
}

TEST_CASE("Rotates correct amount")
{
    Movable m;
    auto position = m.getPosition();

    CHECK(position->angle == 0);

    m.rotateLeft(PLAYER_ROTATE_SPEED);
    CHECK(position->angle == (360 - PLAYER_ROTATE_SPEED));

    m.rotateRight(PLAYER_ROTATE_SPEED);
    CHECK(position->angle == 0);

    m.rotateRight(PLAYER_ROTATE_SPEED);
    CHECK(position->angle == (PLAYER_ROTATE_SPEED));

    m.rotateLeft(PLAYER_ROTATE_SPEED);
    CHECK(position->angle == 0);
}

TEST_CASE("Rotating right")
{
    Movable m;
    auto position = m.getPosition();

    for (int i = 0; i < 1000; i++)
    {
        auto prevAngle = m.getPosition()->angle;
        m.rotateRight(PLAYER_ROTATE_SPEED);
        CHECK(position->angle >= 0);
        CHECK(position->angle < 360);
        CHECK(position->angle != prevAngle);
    }
}

TEST_CASE("Rotating left")
{
    Movable m;
    auto pos = m.getPosition();

    for (int i = 0; i < 1000; i++)
    {
        auto prevAngle = m.getPosition()->angle;
        m.rotateLeft(PLAYER_ROTATE_SPEED);
        CHECK(pos->angle >= 0);
        CHECK(pos->angle <= 360);
        CHECK(pos->angle != prevAngle);
    }
}

TEST_CASE("Rotates correct amount right")
{
    Movable m;
    auto pos = m.getPosition();

    for (int i = 0; i < 1000; i++)
    {
        auto prevAngle = m.getPosition()->angle;
        m.rotateRight(PLAYER_ROTATE_SPEED);
        int expected = prevAngle + PLAYER_ROTATE_SPEED;
        if (expected > 359)
        {
            expected = expected - 360;
        }
        CHECK(expected == pos->angle);
    }
}

TEST_CASE("Rotates correct amount left")
{
    Movable m;
    auto pos = m.getPosition();

    for (int i = 0; i < 1000; i++)
    {
        auto prevAngle = pos->angle;
        m.rotateLeft(PLAYER_ROTATE_SPEED);
        int expected = prevAngle - PLAYER_ROTATE_SPEED;
        if (expected < 0)
        {
            expected = expected + 360;
        }
        CHECK(expected == pos->angle);
    }
}

TEST_CASE("Move forward")
{
    Movable m;
    m.setPosition((WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2), 0);
    auto pos = m.getPosition();
    auto oldY = pos->y;
    auto expected = oldY - PLAYER_MOVEMENT_SPEED;

    m.moveForward(PLAYER_MOVEMENT_SPEED);
    auto newY = pos->y;

    CHECK(oldY != newY);
    CHECK(expected == newY);
}

TEST_CASE("Move backward")
{
    Movable m;
    m.setPosition((WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2), 0);
    auto pos = m.getPosition();
    auto oldY = pos->y;
    auto expected = oldY + PLAYER_MOVEMENT_SPEED;

    m.moveBackward(PLAYER_MOVEMENT_SPEED);
    auto newY = pos->y;

    CHECK(oldY != newY);
    CHECK(expected == newY);
}

TEST_CASE("Move forward with angle")
{
    Movable m;
    auto pos = m.getPosition();

    for (int i = 0; i < 360; i++)
    {
        m.setPosition((WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2), i);
        m.moveForward(PLAYER_MOVEMENT_SPEED);
        double direction_x = sin(i * M_PI / 180) * PLAYER_MOVEMENT_SPEED;
        double direction_y = cos(i * M_PI / 180) * PLAYER_MOVEMENT_SPEED;
        int expected_x = (WINDOW_WIDTH / 2) + direction_x;
        int expected_y = (WINDOW_HEIGHT / 2) - direction_y;
        CHECK(pos->x == expected_x);
        CHECK(pos->y == expected_y);
    }
}

TEST_CASE("Move backward with angle")
{
    Movable m;
    auto pos = m.getPosition();

    for (int i = 0; i < 360; i++)
    {
        m.setPosition((WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2), i);
        m.moveBackward(PLAYER_MOVEMENT_SPEED);
        double direction_x = sin(i * M_PI / 180) * PLAYER_MOVEMENT_SPEED;
        double direction_y = cos(i * M_PI / 180) * PLAYER_MOVEMENT_SPEED;
        int expected_x = (WINDOW_WIDTH / 2) - direction_x;
        int expected_y = (WINDOW_HEIGHT / 2) + direction_y;
        CHECK_MESSAGE(pos->y == expected_y, " Angle: " << i);
        CHECK_MESSAGE(pos->x == expected_x, " Angle: " << i);
    }
}
