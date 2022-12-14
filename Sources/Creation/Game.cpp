#include "../../Headers/Creation/Game.h"
#include "../../Headers/Creation/Level.h"
#include "../../Headers/Mobile/Player.h"
#include "../../Headers/Trap.h"
#include <string>
#include <iostream>
#include <fstream>

void Game::loadLevel(std::string nameLevel) {
    Level level(std::move(nameLevel));
    board = level.generateBoard();
    // board.display();
}

void Game::launch() {
    board.displayTuto();
    while (board.getPlayer().getLife() == 1) {
        Mobile &player = board.mobiles[0];
        board.display();

        /********** Joueur qui joue **********/
        char caractere;
        cin >> caractere;

        vector<int> initPosition = {player.getPosition()[0], player.getPosition()[1]};

        Empty empty;
        empty.setPosition(initPosition[0], initPosition[1]);
		
		// Initializing trapPos, Trap here to avoid error in switch statement 
        std::pair<int, int> trapPos;  
        Trap trap; 
		
        switch (caractere) {
            case '7':
                player.goTo(Direction::NO);
                break;
            case '8':
                player.goTo(Direction::N);
                break;
            case '9':
                player.goTo(Direction::NE);
                break;
            case '4':
                player.goTo(Direction::O);
                break;
            case '6':
                player.goTo(Direction::E);
                break;
            case '1':
                player.goTo(Direction::SO);
                break;
            case '2':
                player.goTo(Direction::S);
                break;
            case '3':
                player.goTo(Direction::SE);
                break;
			 case '5':
            // Set the trap at the player's current position
            trapPos = std::make_pair(player.getPosition()[0], player.getPosition()[1]);
            trap.setPosition(trapPos);
            board.addTrap(trap);
            player.goTo(Direction::S); // Move PLayer down after setting the trap, this line can be removed
            break;
            default:
                player.goTo(Direction::N);
                break;
        }

        // Limites de la map
        bool isWall = false;
        for (auto & wall : board.walls) {
            if ((player.getPosition()[0] == wall.getPosition()[0]) && (player.getPosition()[1] == wall.getPosition()[1])) {
                isWall = true;
            }
        }
        isWall ? player.setPosition(initPosition[0], initPosition[1]) : board.place(player, empty);

        /********** Fauves **********/
        for (auto &fawn : board.mobiles) {
            if (fawn.getSymbol() != 'O') {
                if (fawn.getLife() != 0) {
                    initPosition = { fawn.getPosition()[0], fawn.getPosition()[1] };
                    empty.setPosition(initPosition[0], initPosition[1]);

                    fawn.moveTo(player, board.getTraps());

                    board.place(fawn, empty);

                    // Si mobile a de la vie
                    for (auto &mobile : board.mobiles) {
                        if (mobile.getSymbol() != fawn.getSymbol()) {
                            fawn.touch(mobile);
                        }
                    }
                }
            }
        }

//
//        /********** Lion qui joue **********/
//        if (board.mobiles[1].getLife() != 0) {
//            initPosition = { board.mobiles[1].getPosition()[0], board.mobiles[1].getPosition()[1] };
//            empty.setPosition(initPosition[0], initPosition[1]);
//
//            if (board.mobiles[0].getPosition()[0] < board.mobiles[1].getPosition()[0]) {
//                board.mobiles[1].goTo(Direction::N);
//            } else if (board.mobiles[0].getPosition()[0] > board.mobiles[1].getPosition()[0]) {
//                board.mobiles[1].goTo(Direction::S);
//            } else if (board.mobiles[0].getPosition()[1] > board.mobiles[1].getPosition()[1]) {
//                board.mobiles[1].goTo(Direction::E);
//            } else if (board.mobiles[0].getPosition()[1] < board.mobiles[1].getPosition()[1]) {
//                board.mobiles[1].goTo(Direction::O);
//            } else {
//                cout << "Joueur s'est fait manger par lion.";
//                board.mobiles[0].setLife(board.mobiles[0].getLife() - 1);
//            }
//
//            board.place(board.mobiles[1], empty);
//
//            // Lion touche joueur
//            if (board.mobiles[1].getPosition()[0] == board.mobiles[0].getPosition()[0] && board.mobiles[1].getPosition()[1] == board.mobiles[0].getPosition()[1]) {
//                cout << "Joueur s'est fait manger par lion.";
//                board.mobiles[0].setLife(board.mobiles[0].getLife() - 1);
//            }
//
//            // Lion touche Tigre
//            if (board.mobiles[2].getLife() != 0) {
//                if (board.mobiles[1].getPosition()[0] == board.mobiles[2].getPosition()[0] && board.mobiles[1].getPosition()[1] == board.mobiles[2].getPosition()[1]) {
//                    cout << "Tigre s'est fait manger par lion.";
//                    board.mobiles[2].setLife(board.mobiles[2].getLife() - 1);
//                    board.mobiles[2].setSymbol('.');
//                }
//            }
//        }
//
//        /********** Tigre qui joue **********/
//        if (board.mobiles[2].getLife() != 0) {
//            initPosition = { board.mobiles[2].getPosition()[0], board.mobiles[2].getPosition()[1] };
//            empty.setPosition(initPosition[0], initPosition[1]);
//
//            if (board.mobiles[0].getPosition()[0] < board.mobiles[2].getPosition()[0]) {
//                if (board.mobiles[0].getPosition()[1] > board.mobiles[2].getPosition()[1]) {
//                    board.mobiles[2].goTo(Direction::NE);
//                } else if (board.mobiles[0].getPosition()[1] < board.mobiles[2].getPosition()[1]) {
//                    board.mobiles[2].goTo(Direction::NO);
//                } else {
//                    board.mobiles[2].goTo(Direction::N);
//                }
//            } else if (board.mobiles[0].getPosition()[0] > board.mobiles[2].getPosition()[0]) {
//                if (board.mobiles[0].getPosition()[1] > board.mobiles[2].getPosition()[1]) {
//                    board.mobiles[2].goTo(Direction::SE);
//                } else if (board.mobiles[0].getPosition()[1] < board.mobiles[2].getPosition()[1]) {
//                    board.mobiles[2].goTo(Direction::SO);
//                } else {
//                    board.mobiles[2].goTo(Direction::S);
//                }
//            } else if (board.mobiles[0].getPosition()[1] > board.mobiles[2].getPosition()[1]) {
//                board.mobiles[2].goTo(Direction::E);
//            } else if (board.mobiles[0].getPosition()[1] < board.mobiles[2].getPosition()[1]) {
//                board.mobiles[2].goTo(Direction::O);
//            } else if (board.mobiles[0].getPosition()[0] == board.mobiles[2].getPosition()[0] && board.mobiles[0].getPosition()[1] == board.mobiles[2].getPosition()[1]) {
//                cout << "Joueur s'est fait manger par tigre.";
//                board.mobiles[0].setLife(board.mobiles[0].getLife() - 1);
//            }
//
//            board.place(board.mobiles[2], empty);
//
//            // Tigre touche joueur
//            if (board.mobiles[2].getPosition()[0] == board.mobiles[0].getPosition()[0] && board.mobiles[2].getPosition()[1] == board.mobiles[0].getPosition()[1]) {
//                cout << "Joueur s'est fait manger par tigre.";
//                board.mobiles[0].setLife(board.mobiles[0].getLife() - 1);
//            }
//
//            // Tigre touche Lion
//            if (board.mobiles[1].getLife() != 0) {
//                if (board.mobiles[2].getPosition()[0] == board.mobiles[1].getPosition()[0] && board.mobiles[2].getPosition()[1] == board.mobiles[1].getPosition()[1]) {
//                    cout << "Lion s'est fait manger par tigre.";
//                    board.mobiles[1].setLife(board.mobiles[1].getLife() - 1);
//                    board.mobiles[1].setSymbol('.');
//                }
//            }
//        }
    }
}

void Game::menu() {
std::cout << "Welcome to the game! Please select one of the following options:\n";
std::cout << "1. Start\n";
std::cout << "2. Create a new game\n";
std::cout << "3. Load a saved game\n";
std::cout << "4. Quit\n";

int selection;
std::cin >> selection;

switch (selection) {
    case 1:
        startGame();
        break;
    case 2:
        createNewGame();
        break;
    case 3:
        loadSavedGame();
        break;
    case 4:
        quit();
        break;
    default:
        std::cout << "Invalid selection. Please try again.\n";
        menu();
    }
}


void Game::startGame() {
    Game game;
    game.loadLevel("level1.lvl");
    game.launch();
}


void Game::createNewGame() {
    std::string levelName;
    std::cout << "Enter the name of the level: ";
    std::cin >> levelName;

    int width, length;
    std::cout << "Enter level width: ";
    std::cin >> width;
    std::cout << "Enter level length: ";
    std::cin >> length;


    int playerX, playerY;
    std::cout << "Enter player position (x y): ";
    std::cin >> playerX >> playerY;


    int lionX, lionY;
    std::cout << "Enter lion position (x y): ";
    std::cin >> lionX >> lionY;


    int tigerX, tigerY;
    std::cout << "Enter tiger position (x y): ";
    std::cin >> tigerX >> tigerY;


    std::ofstream levelFile("levels/" + levelName + ".lvl");
    levelFile << "I " << width << "." << length << std::endl;
    levelFile << "P " << playerX << "." << playerY << std::endl;
    levelFile << "L " << lionX << "." << lionY << std::endl;
    levelFile << "T " << tigerX << "." << tigerY << std::endl;
    levelFile.close();


    Game game;
    game.loadLevel(levelName+ ".lvl");
    game.launch();
}


void Game::loadSavedGame() {
	std::string levelName;
    std::cout << "Enter the name of the level (without .lvl extention) :";
    std::cin >> levelName;

    Game game;
    game.loadLevel(levelName+ ".lvl");
    game.launch();
}


void Game::quit() {
std::cout << "Thanks for playing! Goodbye.\n";
exit(0);
}