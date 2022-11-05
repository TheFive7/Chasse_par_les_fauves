#ifndef PROJET_PROGRAMMATION_S5_ENTITY_H
#define PROJET_PROGRAMMATION_S5_ENTITY_H

#include <vector>

class Entity {
    public:
        std::vector<int> getPosition();
        virtual char getSymbol() const;
    protected:
        std::vector<int> d_position;
        char d_symbol;
};


#endif //PROJET_PROGRAMMATION_S5_ENTITY_H
