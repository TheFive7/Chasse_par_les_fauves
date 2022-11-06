#include "../Headers/Entity.h"

std::vector<int> Entity::getPosition() {
    return d_position;
}

char Entity::getSymbol() const {
    return d_symbol;
}

void Entity::setPosition(int x, int y) {
    d_position[0] = x;
    d_position[1] = y;
}
