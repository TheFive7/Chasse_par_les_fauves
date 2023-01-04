#include "doctest.h"

#include "../Headers/Creation/Board.h"

TEST_SUITE("Test Board class")
{
    TEST_CASE("Test the constructor of the Board class")
    {
        SUBCASE("Test the default constructor")
        {
            Board board1;
            CHECK(board1.getWidth() == 0);
            CHECK(board1.getLength() == 0);
        }
        SUBCASE("Test the parameterized constructor")
        {
            Board board2(5, 7);
            CHECK(board2.getWidth() == 5);
            CHECK(board2.getLength() == 7);
        }
    }

    TEST_CASE("Test the getters and setters of the Board class")
    {
        Board board;
        SUBCASE("Test the getters and setters for the width")
        {
            board.setWidth(10);
            CHECK(board.getWidth() == 10);
        }
        SUBCASE("Test the getters and setters for the length")
        {
            board.setLength(15);
            CHECK(board.getLength() == 15);
        }
    }
}

