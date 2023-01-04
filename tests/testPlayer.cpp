#include "doctest.h"
#include "../Headers/Mobile/Player.h"

TEST_SUITE("Test Player class")
{
    TEST_CASE("Test moving the player")
    {
        Player player;
        REQUIRE(player.getPosition()[0] == 1);
        REQUIRE(player.getPosition()[1] == 1);

        SUBCASE("Test moving the player north") {
            player.goTo(Direction::N);
            REQUIRE(player.getPosition()[0] == 0);
            REQUIRE(player.getPosition()[1] == 1);
        }

        SUBCASE("Test moving the player south") {
            player.goTo(Direction::S);
            REQUIRE(player.getPosition()[0] == 2);
            REQUIRE(player.getPosition()[1] == 1);
        }

        SUBCASE("Test moving the player east") {
            player.goTo(Direction::E);
            REQUIRE(player.getPosition()[0] == 1);
            REQUIRE(player.getPosition()[1] == 2);
        }

        SUBCASE("Test moving the player west") {
            player.goTo(Direction::O);
            REQUIRE(player.getPosition()[0] == 1);
            REQUIRE(player.getPosition()[1] == 0);
        }
    }

    TEST_CASE("Test player life") {
        Player player;
        REQUIRE(player.getLife() == 1);
        player.setLife(5);
        REQUIRE(player.getLife() == 5);
    }


    TEST_CASE("Test player life") {
        Player player;
        REQUIRE(player.getLife() == 1);
        player.setLife(5);
        REQUIRE(player.getLife() == 5);
    }

    TEST_CASE("Test player symbol") {
        Player player;
        REQUIRE(player.getSymbol() == 'O');
        player.setSymbol('X');
        REQUIRE(player.getSymbol() == 'X');
    }

    TEST_CASE("Test player name") {
        Player player;
        REQUIRE(player.getName() == "Joueur");
    }
}
