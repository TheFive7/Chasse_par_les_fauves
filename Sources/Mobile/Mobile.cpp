#include "../../Headers/Mobile/Mobile.h"

void Mobile::goTo(Direction direction) {
    // Convert a direction in a tab
    std::vector<int> tab;
    int result = static_cast<int>(direction);
    for (int i = 0; i < 2; i++) {
        tab.insert(tab.begin(), (result % 100) - 11);
        result = (result - (result % 100)) / 100;
    }

    // cout << "[ " << tab[0] << ", " << tab[1] << " ]" << '\n';
    d_position[0] += tab[0];
    d_position[1] += tab[1];
}

void Mobile::setBoard(Board board) {
    d_board = board;
}
