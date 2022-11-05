#include "../../Headers/Board/Board.h"

#include <iostream>

using namespace std;

Board::Board(int width, int length) : d_width{width}, d_length{length} {
    // Initialize
    for (int i = 0; i < d_width; i++){
        std::vector<Cell> tab;
        d_board.push_back(tab);
    }

    // Fill with Empty Object
    for (int i = 0; i < d_width; i++){
        for (int j = 0; j < d_length; j++){
            d_board[i].emplace_back(i, j);
        }
    }
}

void Board::display() const {
    for (int i = 0; i < d_width; i++) {
        for (int j = 0; j < d_length; j++) {
            d_board[i][j].display();
            cout << ' ';
        }
        cout << endl;
    }
}

int Board::getLength() {
    return d_length;
}

int Board::getWidth() {
    return d_width;
}
