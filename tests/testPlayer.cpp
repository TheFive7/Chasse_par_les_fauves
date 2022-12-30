#include "doctest.h"
#include "../Headers/Mobile/Player.h"

TEST_CASE("Test moving the player")
{
    Player player;
    REQUIRE(player.getPosition()[0] == 1);
    REQUIRE(player.getPosition()[1] == 1);

	SUBCASE("Test moving the player north") {
            player.goTo(Direction::N);
            CHECK(player.getPosition()[0] == 0);
            CHECK(player.getPosition()[1] == 1);
        }

        SUBCASE("Test moving the player south") {
            player.goTo(Direction::S);
            CHECK(player.getPosition()[0] == 2);
            CHECK(player.getPosition()[1] == 1);
        }

        SUBCASE("Test moving the player east") {
            player.goTo(Direction::E);
            CHECK(player.getPosition()[0] == 1);
            CHECK(player.getPosition()[1] == 2);
        }

        SUBCASE("Test moving the player west") {
            player.goTo(Direction::O);
            CHECK(player.getPosition()[0] == 1);
            CHECK(player.getPosition()[1] == 0);
        }
}

TEST_CASE("Test player life") {
	Player player;
	REQUIRE(player.getLife() == 1);
	player.setLife(5);
	CHECK(player.getLife() == 5);
}

TEST_CASE("Test player symbol") {
	Player player;
	REQUIRE(player.getSymbol() == 'O');
	player.setSymbol('X');
	CHECK(player.getSymbol() == 'X');
}

TEST_CASE("Test player name") {
	Player player;
	REQUIRE(player.getName() == "Joueur");
}
