#include "board.h"
#include "display.h"
#include "colors.h"
#include <iostream>
#include <string>
using namespace std;


struct Board {
    int columns;
    int rows;
    int numberOfMines;
    int xLocation; // x coordinate of the player's cursor
    int yLocation; // y coordinate of the player's cursor
    char mineBoard[16][30]; // board with only 'B'
    char playerBoard[16][30]; // board that the player sees
        // these char arrays need to be edited so that their columns and rows are changeable.
    int currentScore;

    void setBoardSize();
    void setBoard();
    void printBoard();
    void getPlayerInput();
    void uncover(int x, int y);
    void flagging();
};


void Board::setBoardSize() {
    // get input for columns and rows. or setting the difficulty i guess
}


void Board::setBoard() {
    // randomize the bombs in mineBoard.
    // note that the first input (the first 'reveal') is on (xLocation, yLocation) coordinates.
    // the first cell + the 3x3 surrounding cells are guaranteed to be empty.
}


// needs to be edited to highlight or point to where the cursor is currently located
void Board::printBoard() {
    system("clear");

    string corners[9] = {"┌", "┬", "┐", "├", "┼", "┤", "└", "┴", "┘"};
    int l = 0;

    for (int i = 0; i < rows; ++i) {
        if (i != 0) {
            l = 3;
        }

        cout << corners[l] << "─────";

        for (int j = 1; j < columns; ++j) {
            cout << corners[l+1] << "─────";
        }

        cout << corners[l+2];
        cout << '\n';

        for (int j = 0; j < columns; ++j) {
            cout << "│  " << playerBoard[i][j] << "  ";
        }
        cout << "│" << '\n';
    }

    cout << corners[6] << "─────";
    for (int j = 1; j < columns; ++j) {
            cout << corners[7] << "─────";
        }
    cout << corners[8];

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
            uncover(xLocation, yLocation);
            validInput = true;
            break;

        case 'p':
            flagging();
            validInput = true;
            break;

        default:
            break;
        }
        
        if (!validInput) {
            printBoard();
            cout << "invalid input";
        }

    } while (!validInput);

}


void Board::uncover(int x, int y) {
    if (mineBoard[y][x] == 'B') {
        currentScore -= 100;
        playerBoard[y][x] = '@';
        cout << "You uncovered a mine!\n";
        // not final. need to figure out a way to format this message below the board.
        return;
    }
    
    playerBoard[y][x] = '.';
    int surroundingMineCount = 48;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if (i == 0 && j == 0) {
                continue;
            }

            int neighborX = x + i;
            int neighborY = y + j;

            bool cellOutOfRange = (neighborX < 0 || neighborX >= columns || neighborY < 0 || neighborY >= rows);
            if (cellOutOfRange) {
                continue;
            }

            if (mineBoard[neighborY][neighborX] == 'B') {
                surroundingMineCount++;
            }
        }
    }

    if (surroundingMineCount != 48) {
        playerBoard[y][x] = char(surroundingMineCount);
        return;
    }

    // recursively uncover the neighboring cells if surroundingMineCount is 0.
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if (i == 0 && j == 0) {
                continue;
            }

            int neighborX = x + i;
            int neighborY = y + j;

            bool cellOutOfRange = (neighborX < 0 || neighborX >= columns || neighborY < 0 || neighborY >= rows);
            if (cellOutOfRange) {
                continue;
            }

            if (playerBoard[neighborY][neighborX] == '.') {
                continue;
            }

            uncover(neighborX, neighborY);
        }
    }
}

// 'F' for flags? not final. Also, the scores need to be adjusted.
void Board::flagging() {
    if (playerBoard[yLocation][xLocation] == 'F') {
        playerBoard[yLocation][xLocation] = ' ';
        numberOfMines += 1;
        return;
    }

    playerBoard[yLocation][xLocation] = 'F';
    numberOfMines -= 1;

    if (mineBoard[yLocation][xLocation] == 'B') {
        currentScore += 10;
    } else {
        currentScore -= 100;
    }
}
