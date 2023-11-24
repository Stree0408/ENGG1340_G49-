#ifndef BOARD_H
#define BOARD_H
using namespace std;

struct Board {
    int columns;
    int rows;
    int numberOfFlags;
    int xLocation;
    int yLocation;
    char mineBoard[16][30];
    char playerBoard[16][30];
    int currentScore;

    void setBoardSize();
    void setBoard();
    void printBoard();
    char getPlayerInput(bool IsFirstTimePlaying);
    void uncover(int x, int y);
    void flagging();
};

#endif
