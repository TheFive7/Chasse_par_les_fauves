#ifndef PROJET_PROGRAMMATION_S5_TRAP_H
#define PROJET_PROGRAMMATION_S5_TRAP_H

#include <utility>  // for std::pair
#include <iostream>

class Trap {
public:
    Trap(std::pair<int, int> position);
	Trap();
    std::pair<int, int> getPosition() const;
    void setPosition(std::pair<int, int> position);
    void setSymbol(char symbol);
    char getSymbol() const;
private:
    std::pair<int, int> d_position;
    char d_symbol;
};

#endif //PROJET_PROGRAMMATION_S5_TRAP_H