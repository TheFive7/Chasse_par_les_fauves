#include "doctest.h"

#include "../Headers/Trap.h"

TEST_SUITE("Test Trap class")
{
    TEST_CASE("Test position getters and setters")
    {
        Trap t{std::pair(1, 2)};

        SUBCASE("Test getters sub case") {
            REQUIRE(t.getPosition().first == 1);
            REQUIRE(t.getPosition().second == 2);
        }
        SUBCASE("Test setters sub case") {
            t.setPosition(std::pair(3, 4));
            REQUIRE(t.getPosition().first == 3);
            REQUIRE(t.getPosition().second == 4);
        }
    }

    TEST_CASE("Test symbol getters and setters")
    {
        Trap t;
        SUBCASE("Test getters sub case") {
            REQUIRE(t.getSymbol() == '#');
        }
        SUBCASE("Test setters sub case") {
            t.setSymbol('X');
            REQUIRE(t.getSymbol() == 'X');
        }
    }

    TEST_CASE("Test constructors") {
        SUBCASE("Test default constructor sub case") {
            Trap defaultTrap;
            REQUIRE(defaultTrap.getSymbol() == '#');
        }
         SUBCASE("Test parameterized constructor sub case") {
            std::pair<int, int> position{3, 5};
            Trap paramTrap(position);
            REQUIRE(paramTrap.getPosition().first == 3);
            REQUIRE(paramTrap.getPosition().second == 5);
            REQUIRE(paramTrap.getSymbol() == '#');
         }
    }
}
