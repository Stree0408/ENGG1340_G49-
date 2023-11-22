#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "board.h"
using namespace std;


char **board;
char **tmp_board;
int row;
int col;



void customize()
{
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


// generate board with size of row*col, fill in with '-' first
void make_board()
{
    // make the main board
    board = new char*[row];
    for(int i=0; i<row; i++) {
        board[i] = new char[col];
    }
    
    // make tmp_board
    tmp_board = new char*[row];
    for(int i=0; i<row; i++) {
        tmp_board[i] = new char[col];
    }
    
    for(int i = 0; i < row; ++i) 
    {
        for(int j = 0; j < col; ++j)
            board[i][j] =  tmp_board[i][j] = '.';
    }
}


// printout the main board
void print_board() {
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}



// printout the tmp board
void print_tmp_board() {
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            cout << tmp_board[i][j] << ' ';
        }
        cout << '\n';
    }
}



int cnt_mines(int x, int y)     // x == row, y == column
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
            if (board[i][j] == 'B')
                cnt++;
        }
    }
    return cnt;
}
         


void place_mines(int x, int y)
{

    
    board[x][y]='H';
    
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
        
        if (board[rnd_r][rnd_c] == 'B')
        {
            i--; continue;
        }
        else
            board[rnd_r][rnd_c] = 'B';
    }
    
    
//    for (int i=0; i<row; i++)
//    {
//        for (int j=0; j<col; j++)
//        {
//            if (board[i][j] != 'B' && board[i][j] != 'H')
//                board[i][j] = 48+cnt_mines(i, j);
//        }
//    }
}


void reveal_cells(int x, int y)
{
    
}

         

void del_dynamic()
{
    for(int i=0; i<row; i++)
        delete[] board[i];
    delete[] board;
    
    board = nullptr;
}
         
         

int main()
{
    customize();
    make_board();
    print_board();
    
    int x,y;    // x = row, y = col
    cin >> x >> y;      // 플레이어가 처음 클릭하는 좌표 (여기기준 3x3은 폭탄없어야함)
    
    
    place_mines(x,y);
    print_board();
    print_tmp_board();
    
//    reveal_cells(<#int x#>, <#int y#>)(x,y);
    
    del_dynamic();      // 맨 마지막에, 동적메모리 풀어줘야함
    return 0;
}
