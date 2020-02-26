
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "Player/Player.hpp"

class PlayerTest : public ::testing::Test
{
  protected:
    PlayerTest()
    {
    }
};

TEST_F(PlayerTest, Initial)
{
    EXPECT_EQ(2, 1 + 1);
}