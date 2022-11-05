#include "../../Headers/Mobile/Player.h"

int Player::getLife() const {
    return d_life;
}

Player::Player() {
    d_symbol = 'O';
}
