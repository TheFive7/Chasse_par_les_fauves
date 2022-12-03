#include <iostream>
#include <string>
#include <conio.h>

#include "GameManager.h"

using std::cout;
using std::cin;
using std::string;

int main() {
    GameManager gameManager("C:\\Users\\Maxime\\CLionProjects\\Chasse_par_les_fauves\\Levels\\level1.sav");

    gameManager.runGame();

    cout << "\n Press ENTER to continue...\n";
    getch();
    return 0;
}