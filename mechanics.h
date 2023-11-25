#ifndef MECHANICS_H
#define MECHANICS_H

struct Board {
    int column;
    int row;
    int numberOfFlags;
    int numberOfMines;
    int xLocation;
    int yLocation;
    char **mineBoard;
    char **playerBoard;
    int currentScore;

    void setBoardSize();
    void setBoard();
    void placeMines();
    void delDynamic();
    void printBoard();
    char getPlayerInput(bool IsFirstTimePlaying);
    void uncover(int x, int y);
    void flagging();
    void endGame(int currentScore);
    void leaderboard(int currentScore);
    bool checkEndGame(); 


};

#endif
