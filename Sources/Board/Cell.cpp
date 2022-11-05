#include "../../Headers/Board/Cell.h"
#include "../../Headers/Field/Empty.h"
#include <iostream>
#include <utility>

Entity Cell::getContent() {
    return d_content;
}

void Cell::display() const {
    std::cout << d_content.getSymbol();
}

Cell::Cell(int x, int y) : d_content{Empty()}, d_x{x}, d_y{y} {}

void Cell::displayCoordonates() const {
    std::cout << d_x << ", " << d_y ;
}

