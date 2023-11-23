#ifndef execute_h
#define execute_h

// 항상 row * col (not col * row)
struct Board {
    int row;
    int col;
    int nMines;
    int x; // x coordinate of the player's cursor
    int y; // y coordinate of the player's cursor
    char **mainBoard; // board with only 'B'
    char **playerBoard; // board that the player sees
        // these char arrays need to be edited so that their columns and rows are changeable.   

    void customize();
    void setBoard();    // set mainBoard and playerBoard
    void printMainBoard();
    void printPlayerBoard();
    int cntMines(int x, int y);
    void placeMines(int x, int y);
    void delDynamic();
    
    
//    int currentScore;
//    char getPlayerInput(bool IsFirstTimePlaying);
//    void uncover(int x, int y);
//    void flagging();
};


#endif /* execute_h */
