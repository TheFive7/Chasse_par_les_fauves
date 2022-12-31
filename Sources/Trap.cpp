#include <iostream>
#include "../Headers/Trap.h"

Trap::Trap(std::pair<int, int> position) : d_position{position}, d_symbol{'#'}
{
}

std::pair<int, int> Trap::getPosition() const
{
    return d_position;
}

void Trap::setPosition(std::pair<int, int> position)
{
    this->d_position = position;
}

void Trap::setSymbol(char symbol)
{
    d_symbol = symbol;
}


char Trap::getSymbol() const
{
    return d_symbol;
}