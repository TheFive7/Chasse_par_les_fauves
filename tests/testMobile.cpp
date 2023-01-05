#include "doctest.h"
#include "../Headers/Mobile/Mobile.h"


TEST_SUITE("Mobile") {
    TEST_CASE("constructor") {
        Mobile mobile;
        REQUIRE(mobile.getLife() == 1);
        REQUIRE(mobile.getSymbol() == '.');
        REQUIRE(mobile.getPosition() == std::vector<int>{1, 1});
    }

    TEST_CASE("setters and getters") {
        Mobile mobile;
        mobile.setLife(2);
        mobile.setSymbol('O');
        mobile.setPosition({2, 2});
        REQUIRE(mobile.getLife() == 2);
        REQUIRE(mobile.getSymbol() == 'O');
        REQUIRE(mobile.getPosition() == std::vector<int>{2, 2});
    }

    TEST_CASE("touch") {
        Mobile lion;
        lion.setSymbol('L');
        lion.setPosition({1, 1});

        Mobile fawn;
        fawn.setSymbol('F');
        fawn.setPosition({1, 1});
        lion.touch(fawn);

        REQUIRE(fawn.getLife() == 0);
        REQUIRE(fawn.getSymbol() == '.');
    }

    TEST_CASE("moveTo") {
        Mobile tiger;
        tiger.setSymbol('T');
        tiger.setPosition({1, 1});

        Mobile fawn;
        fawn.setSymbol('F');
        fawn.setPosition({5, 5});

        std::vector<Trap> traps;
        tiger.moveTo(fawn, traps);

        REQUIRE(tiger.getPosition() == std::vector<int>{2, 2});

        // Add a trap on the next position
        traps.emplace_back(std::pair<int, int>{2, 2});
        tiger.moveTo(fawn, traps);

        REQUIRE(tiger.getPosition() == std::vector<int>{1, 1});
        REQUIRE(tiger.getLife() == 0);
        REQUIRE(tiger.getSymbol() == '.');
    }
}