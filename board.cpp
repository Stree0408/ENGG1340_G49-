#include "board.h"
#include <iostream>
using namespace std;


struct Board {
    const int columns;
    const int rows;
    int xLocation;
    int yLocation;
    char playerBoard[16][30];

    void setBoard() {

    }

    void printBoard() {
        system("clear");
    }

    void getPlayerInput() {
        char playerInput;
        printBoard();
        cout << "input the direction you want to head. "
                "if you put in multiple characters, "
                "only the first one will be considered.";

        while (true) {
            cin >> playerInput;

            switch (playerInput) {
            case 'w':
                if (yLocation + 1 >= rows) {
                    ++yLocation;
                    return;
                } else {
                    printBoard();
                    cout << "invalid input. please go to another direction.";
                    continue;
                }

            case 'a':
                if (xLocation - 1 < 0) {
                    --xLocation;
                    return;
                } else {
                    printBoard();
                    cout << "invalid input. please go to another direction.";
                    continue;
                }

            case 's':
                if (yLocation - 1 < 0) {
                    --yLocation;
                    return;
                } else {
                    printBoard();
                    cout << "invalid input. please go to another direction.";
                    continue;
                }

            case 'd':
                if (xLocation + 1 >= columns) {
                    ++xLocation;
                    return;
                } else {
                    printBoard();
                    cout << "invalid input. please go to another direction.";
                    continue;
                }

            case 'o':
                uncover();
                return;

            case 'p':
                flagging();
                return;

            default:
                cout << "invalid input";
                continue;
        }
        }

    }

    void uncover() {

    }

    void flagging() {

    }


};
