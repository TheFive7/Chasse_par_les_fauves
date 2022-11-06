#include "../../Headers/Board/Board.h"

#include <iostream>
#include <utility>

using namespace std;

Board::Board(int width, int length) : d_width{width}, d_length{length} {
    // Initialize
    d_player = Player();
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
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
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

void Board::placeEntity(Entity content, int x, int y) {
    content.setPosition(x, y);
    d_board[x][y].setContent(std::move(content));
}

std::vector<std::vector<Cell>> Board::getBoard() {
    return d_board;
}

Player* Board::getPlayer() {
    return d_player;
}
