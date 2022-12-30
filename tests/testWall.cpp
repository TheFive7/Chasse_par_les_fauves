#include "doctest.h"

#include "../Headers/Obstacle/Wall.h"
#include <vector>

using namespace std;

TEST_CASE("Test Wall class")
{
    SUBCASE("Test Wall initialization")
    {
        Wall wall;
        REQUIRE(wall.getSymbol() == '#');
        REQUIRE(wall.getPosition().empty());
    }
    SUBCASE("Test Wall positioning")
    {
        Wall wall;
        vector<int> position{ 2, 3 };
        wall.setPosition(position[0], position[1]);
        REQUIRE(wall.getPosition() == position);
    }
}