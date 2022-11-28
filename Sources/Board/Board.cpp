#include "../../Headers/Board/Board.h"
#include "../../Headers/Field/Empty.h"

#include <iostream>
#include <utility>

using namespace std;

Board::Board(int width, int length) : d_width{width}, d_length{length} {
    // Initialize
//    d_player = Player();
    for (int i = 0; i < d_width; i++){
        std::vector<Entity> tab;
        d_board.push_back(tab);
    }

    // Fill with Empty Object
    for (int i = 0; i < d_width; i++){
        for (int j = 0; j < d_length; j++){
            Empty empty;
            d_board[i].emplace_back(empty);
        }
    }
}

void Board::display() const {
    cout << endl;
    for (int i = 0; i < d_width; i++) {
        for (int j = 0; j < d_length; j++) {
            d_board[i][j].getSymbol();
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

std::vector<std::vector<Entity>> Board::getBoard() {
    return d_board;
}

//Player* Board::getPlayer() {
//    return d_player;
//}
