#include <iostream>
#include <vector>
#include <synchapi.h>
#include "Headers/Board/Board.h"
#include "Headers/Mobile/Player.h"

using namespace std;

int main() {
    Board board = {10, 10};
    board.display();

    cout << endl;
    Sleep(2000);

    Player player;
    player.setBoard(board);
    board.replace(player, 2, 2);
    board.display();

    while (player.getLife() == 1) {
        Sleep(2000);
        board.display();
        player.goTo(Direction::S);
    }
    return 0;
}
