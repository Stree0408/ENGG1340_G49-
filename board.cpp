#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "execute.h"
using namespace std;



// player customize their own board
void Board::customize() {
    cout << "CUSTOMIZE YOUR OWN BOARD, OWN GAME!!" << endl;
    cout << "ENTER NUMBER BETWEEN 8-16 FOR ROWS : ";
    cin >> row;
    cout << "ENTER NUMBER BETWEEN 8-30 FOR COLUMNS : ";
    cin >> col;
    
    while ( row<8 || row>16)
    {
        cout << "Please enter the row again : ";
        cin >> row;
    }
    
    while ( col<8 || col >30 )
    {
        cout << "Please enter the col again : ";
        cin >> col;
    }
}


// note that the first input (the first 'reveal') is on (xLocation, yLocation) coordinates.
// the first cell + the 3x3 surrounding cells are guaranteed to be empty.
// generate board with size of row*col, fill in with '-' first
void Board::setBoard() {
    // make the main board
    mainBoard = new char*[row];
    for(int i=0; i<row; i++) {
        mainBoard[i] = new char[col];
    }
    
    // make player board
    playerBoard = new char*[row];
    for(int i=0; i<row; i++) {
        playerBoard[i] = new char[col];
    }
    
    for(int i=0; i<row; i++)
    {
        for(int j = 0; j < col; ++j)
            mainBoard[i][j] = playerBoard[i][j] = '.';
    }
}


//void Board::printMainBoard()
//{
//    for(int i = 0; i < row; ++i) {
//        for(int j = 0; j < col; ++j) {
//            cout << mainBoard[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//}


void Board::printPlayerBoard()
{
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j) {
            cout << playerBoard[i][j] << ' ';
        }
        cout << '\n';
    }
}

int Board::cntMines(int x, int y)     // x == row, y == column
{
    int cnt=0;
    int low_x = x-1, high_x= x+1;   // row
    int low_y = y-1, high_y= y+1;   // column
    
    if (x==0)
        low_x = x;
    if (x==row-1)
        high_x = x;
    if (y==0)
        low_y = y;
    if (y==col-1)
        high_y = y;
    
    for (int i=low_x; i<=high_x; i++)
    {
        for (int j=low_y; j<=high_y; j++)
        {
            if (mainBoard[i][j] == 'B')
                cnt++;
        }
    }
    return cnt;
}


// randomize the bombs in mainBoard & put B on the spot with bomb
void Board::placeMines(int x, int y)
{
    mainBoard[x][y]='H';
    
    int nMines = (row*col) * 0.2;
    //    cout << nMines << endl;
    
    int rnd_r, rnd_c;   // random input for row and column
    
    srand(time(NULL));
    for (int i=0; i<nMines; i++)
    {
        rnd_r = rand() % row;
        rnd_c = rand() % col;
        
        while (rnd_r>=x-1 && rnd_r<=x+1)
            rnd_r = rand() % row;
        
        while (rnd_c>=y-1 && rnd_c<=y+1)
            rnd_c = rand() % col;
        
        if (mainBoard[rnd_r][rnd_c] == 'B')
        {
            i--; continue;
        }
        else
            mainBoard[rnd_r][rnd_c] = 'B';
    }
}



void Board::delDynamic()
{
    for(int i=0; i<row; i++)
        delete[] mainBoard[i];
    delete[] mainBoard;
    
    mainBoard = nullptr;
}
     



// needs to be edited to highlight or point to where the cursor is currently located
void Board::printMainBoard() {
    system("clear");

    string corners[9] = {"┌", "┬", "┐", "├", "┼", "┤", "└", "┴", "┘"};
    int l = 0;

    for (int i = 0; i < row; ++i) {
        if (i != 0) {
            l = 3;
        }

        cout << corners[l] << "─────";

        for (int j = 1; j < col; ++j) {
            cout << corners[l+1] << "─────";
        }

        cout << corners[l+2] << '\n';

        for (int j = 0; j < col; ++j) {
            if (i == y && j == x){
//                cout << "│  " << blueBackground << playerBoard[i][j] << reset << "  ";
                cout << "│  "  << mainBoard[i][j] << "  ";      // 잘 바뀌는지 확인해보려고 mainboard로 바꿨음
                continue;
            }
            cout << "│  " << mainBoard[i][j] << "  ";
        }
        cout << "│" << '\n';
    }

    cout << corners[6] << "─────";
    for (int j = 1; j < col; ++j) {
            cout << corners[7] << "─────";
        }
    cout << corners[8];
}



//char Board::getPlayerInput(bool IsFirstTimePlaying) {
//    char playerInput;
//    printBoard();
//    cout << "input the direction you want to head. "
//            "if you put in multiple characters, "
//            "only the first one will be considered.\n";
//
//    bool validInput = false;
//    do {
//        cin >> playerInput;
//
//        switch (playerInput) {
//        case 's':
//        case 'S':
//            if (yLocation + 1 < row) {
//                ++yLocation;
//                validInput = true;
//            }
//            break;
//
//        case 'a':
//        case 'A':
//            if (xLocation - 1 >= 0) {
//                --xLocation;
//                validInput = true;
//            }
//            break;
//
//        case 'w':
//        case 'W':
//            if (yLocation - 1 >= 0) {
//                --yLocation;
//                validInput = true;
//            }
//            break;
//
//        case 'd':
//        case 'D':
//            if (xLocation + 1 < columns) {
//                ++xLocation;
//                validInput = true;
//            }
//            break;
//
//        case 'o':
//        case 'O':
//            if (IsFirstTimePlaying == true) {
//                return 'o';
//            }
//            uncover(xLocation, yLocation);
//            validInput = true;
//            break;
//
//        case 'p':
//        case 'P':
//            if (IsFirstTimePlaying == true) {
//                break;
//            }
//            flagging();
//            validInput = true;
//            break;
//
//        case 'm':
//        case 'M':
//            validInput = true;
//            return 'm';
//
//        default:
//            break;
//        }
//        
//        if (!validInput) {
//            printBoard();
//            cout << "invalid input. please enter again.\n";
//        }
//
//    } while (!validInput);
//
//    return '.';
//
//}


//void Board::uncover(int x, int y) {
//    if (mineBoard[y][x] == 'B') {
//        currentScore -= 100;
//        playerBoard[y][x] = '@';
//        cout << "You uncovered a mine!\n";
//        // not final. need to figure out a way to format this message below the board.
//        return;
//    }
//    
//    playerBoard[y][x] = '.';
//    int surroundingMineCount = 48;
//
//    for (int i = -1; i <= 1; i++) {
//        for (int j = -1; j <= 1; j++) {
//
//            if (i == 0 && j == 0) {
//                continue;
//            }
//
//            int neighborX = x + i;
//            int neighborY = y + j;
//
//            bool cellOutOfRange = (neighborX < 0 || neighborX >= columns || neighborY < 0 || neighborY >= rows);
//            if (cellOutOfRange) {
//                continue;
//            }
//
//            if (mineBoard[neighborY][neighborX] == 'B') {
//                surroundingMineCount++;
//            }
//        }
//    }
//
//    if (surroundingMineCount != 48) {
//        playerBoard[y][x] = char(surroundingMineCount);
//        return;
//    }
//
//    // recursively uncover the neighboring cells if surroundingMineCount is 0.
//    for (int i = -1; i <= 1; i++) {
//        for (int j = -1; j <= 1; j++) {
//
//            if (i == 0 && j == 0) {
//                continue;
//            }
//
//            int neighborX = x + i;
//            int neighborY = y + j;
//
//            bool cellOutOfRange = (neighborX < 0 || neighborX >= col || neighborY < 0 || neighborY >= row);
//            if (cellOutOfRange) {
//                continue;
//            }
//
//            if (playerBoard[neighborY][neighborX] == '.') {
//                continue;
//            }
//
//            uncover(neighborX, neighborY);
//        }
//    }
//}

// 'F' for flags? not final. Also, the scores need to be adjusted.
//void Board::flagging() {
//    if (playerBoard[yLocation][xLocation] == 'F') {
//        playerBoard[yLocation][xLocation] = ' ';
//        numberOfMines += 1;
//        return;
//    }
//
//    playerBoard[yLocation][xLocation] = 'F';
//    numberOfMines -= 1;
//
//    if (mineBoard[yLocation][xLocation] == 'B') {
//        currentScore += 10;
//    } else {
//        currentScore -= 100;
//    }
//}
