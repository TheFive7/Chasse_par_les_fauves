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

//    while (board.getPlayer().getLife() != 0) {
//        Sleep(2000);
//        board.display();
//    }
    return 0;
}
