#include "../Headers/Empty.h"
using namespace std;

Empty::Empty() {
    d_symbol = '.';
    setPosition(0, 0);
}

vector<int> Empty::getPosition() {
    return d_position;
}

char Empty::getSymbol() const {
    return d_symbol;
}

void Empty::setPosition(int x, int y) {
    d_position[0] = x;
    d_position[1] = y;
}

Empty::Empty(int x, int y) {
    d_symbol = '.';
    setPosition(x, y);
}
