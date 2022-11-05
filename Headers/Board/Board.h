#ifndef PROJET_PROGRAMMATION_S5_BOARD_H
#define PROJET_PROGRAMMATION_S5_BOARD_H

#include <vector>
#include "Cell.h"

class Board {
    public:
        Board(int width, int length);
        void display() const;
        int getLength();
        int getWidth();
    private:
        int d_width;
        int d_length;
        std::vector<std::vector<Cell>> d_board;
};


#endif //PROJET_PROGRAMMATION_S5_BOARD_H
