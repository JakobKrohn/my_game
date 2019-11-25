#include "doctest/doctest.h"

#include "Settings.hpp"
#include "src/modules/movable/player/Player.hpp"

TEST_CASE("Player name") {
    Player player("jakob");
    CHECK(player.name_ == "jakob");
}
