#include "../../Headers/Mobile/Player.h"

int Player::getLife() const {
    return d_life;
}

Player::Player() {
    d_symbol = 'O';
    d_position.push_back(1);
    d_position.push_back(1);
}
