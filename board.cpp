#include "runGame.h"
#include <iostream>
using namespace std;


struct Board {
    const int columns;
    const int rows;
    int xLocation;
    int yLocation;
    char playerBoard[16][30];

    void setBoard();
    void printBoard();
    void getPlayerInput();
    void uncover();
    void flagging();

};


void Board::setBoard() {
}


void Board::printBoard() {
    system("clear");
}


void Board::getPlayerInput() {
    char playerInput;
    printBoard();
    cout << "input the direction you want to head. "
            "if you put in multiple characters, "
            "only the first one will be considered.";

    bool validInput = false;
    do {
        cin >> playerInput;

        switch (playerInput) {
        case 'w':
            if (yLocation + 1 >= rows) {
                ++yLocation;
                validInput = true;
            }
            break;

        case 'a':
            if (xLocation - 1 < 0) {
                --xLocation;
                validInput = true;
            }
            break;

        case 's':
            if (yLocation - 1 < 0) {
                --yLocation;
                validInput = true;
            }
            break;

        case 'd':
            if (xLocation + 1 >= columns) {
                ++xLocation;
                validInput = true;
            }
            break;

        case 'o':
            uncover();
            validInput = true;
            break;

        case 'p':
            flagging();
            validInput = true;
            break;

        default:
            cout << "invalid input";
            break;
        }
        
        if (!validInput) {
            printBoard();
            cout << "invalid input";
        }

    } while (!validInput);

}


void Board::uncover() {
}


void Board::flagging() {
}



void runGame(Board b){
    b.setBoard();
}
