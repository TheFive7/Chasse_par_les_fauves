#ifndef PROJET_PROGRAMMATION_S5_BOARD_H
#define PROJET_PROGRAMMATION_S5_BOARD_H

#include <vector>
#include "Cell.h"
#include "../Mobile/Player.h"

class Board {
    public:
        Board(int width, int length);//je pense qu'il faut plutot faire un constructeur par défaut ou on ouvre un fichier
        void display() const;
        void placeEntity(Entity content, int x, int y);
        std::vector<std::vector<Cell>> getBoard();
        int getLength();
        int getWidth();
        Player* getPlayer();
    private:
    //certaines infos se trouve dans le fichier sauvegarde
        int d_width;
        int d_length;
        Player d_player;
        std::vector<std::vector<Cell>> d_board;//surement changer Cell
};


#endif //PROJET_PROGRAMMATION_S5_BOARD_H
