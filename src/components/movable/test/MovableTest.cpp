
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "Movable/Movable.hpp"

class MovableTest : public ::testing::Test
{
  protected:
    MovableTest()
    {
    }
};

TEST_F(MovableTest, Setup)
{
    // components::Movable movable;
    EXPECT_EQ(2, 1 + 1);
}