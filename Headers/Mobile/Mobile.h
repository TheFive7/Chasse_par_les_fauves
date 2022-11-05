#ifndef PROJET_PROGRAMMATION_S5_MOBILE_H
#define PROJET_PROGRAMMATION_S5_MOBILE_H

#include <vector>
#include "../Entity.h"
#include "../Board/Board.h"

enum class Direction {
    // -1 = 10; 0 = 11, 1 = 12
    NO = 1010,
    N = 1011,
    NE = 1012,
    O = 1110,
    E = 1112,
    SO = 1210,
    S = 1211,
    SE = 1212
};

class Mobile : public Entity {
    public:
        void setBoard(Board board);
        virtual void goTo(Direction direction);
    protected:
        int d_life = 1;
        Board d_board = Board(0, 0);
};


#endif //PROJET_PROGRAMMATION_S5_MOBILE_H
