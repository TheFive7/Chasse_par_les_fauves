#include "../Headers/Entity.h"

std::vector<int> Entity::getPosition() {
    return d_position;
}

char Entity::getSymbol() const {
    return d_symbol;
}
