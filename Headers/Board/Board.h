#ifndef PROJET_PROGRAMMATION_S5_BOARD_H
#define PROJET_PROGRAMMATION_S5_BOARD_H

#include <vector>
#include "Cell.h"
#include "../Mobile/Player.h"

class Board {
    public:
        Board(int width, int length);
        void display() const;
        void placeEntity(Entity content, int x, int y);
        std::vector<std::vector<Cell>> getBoard();
        int getLength();
        int getWidth();
        Player* getPlayer();
    private:
        int d_width;
        int d_length;
        Player d_player;
        std::vector<std::vector<Cell>> d_board;
};


#endif //PROJET_PROGRAMMATION_S5_BOARD_H
