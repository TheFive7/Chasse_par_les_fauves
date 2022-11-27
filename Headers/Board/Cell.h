#ifndef PROJET_PROGRAMMATION_S5_CELL_H
#define PROJET_PROGRAMMATION_S5_CELL_H

#include <vector>
#include <memory>
#include "../Entity.h"
#include "../Field/Empty.h"
//va surement etre changé par entity
class Cell {
    public:
        Cell(int x, int y);
        Entity getContent();
        void display() const;
        void setContent(Entity content);
        void displayCoordonates() const;
    private:
        Entity d_content;
        int d_x;
        int d_y;
};


#endif //PROJET_PROGRAMMATION_S5_CELL_H
