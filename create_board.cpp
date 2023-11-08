
//보드 2개 만들기 (24x20, 폭탄 99개) (박찬혁)
//Make an array of arr[24][20] = {0};  → map
//Randomly distribute 폭탄 on the map → 폭탄있는곳에는 o, 없는곳에는 x
//동일한 맵에, x인곳들에 (폭탄없는곳)
//주변 폭탄 갯수 (특정 구역만 랜덤하게 - 어느정도 붙어있게 random돌려서)



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// if it has bomb : 'B', if it is empty : '.'
void make_board(char board[16][30])
{
    // fill the board with '.'
    for (int i=0; i<16; i++)
    {
        for (int j=0; j<30; j++)
        {
            board[i][j] = '.';
        }
    }
    
    // generate bomb randomly
    srand(time(0));
    int rnd;
    for (int i=0; i<16; i++)
    {
        for (int j=0; j<6; j++)
        {
            rnd = rand() % 30;
            if ((board[i][rnd]) == '.')
            {
                board[i][rnd] = 'V';
            }
            else
            {
                j--; continue;
            }
        }
    }
    
    // count how many bombs around each space
    int cnt;
    for (int i=0; i<16; i++)
    {
        for (int j=0; j<30; j++)
        {
            if (board[i][j] != 'V')
            {
                int low_i = i-1, high_i= i+1;   // row
                int low_j = j-1, high_j= j+1;   // column
                cnt=0;
                
                if (i==0)
                    low_i = i;
                if (i==29)
                    high_i = i;
                if (j==0)
                    low_j = j;
                if (j==29)
                    high_j = j;
                
                
                for (int k=low_i; k<=high_i; k++)
                {
                    for (int m=low_j; m<=high_j; m++)
                    {
                        if (board[k][m] == 'V')
                            cnt++;
                    }
                }
                board[i][j] = cnt+ 48;
            }
            else
                continue;
        }
    }

    
    
    
    // 포인터 아직 안배워서  배열가지고 배꼈음
    char new_board[16][30]={0};

//    for (int i=0; i<16; i++)
//    {
//        for (int j=0; j<30; j++)
//        {
//            new_board[i][j] = board[i][j];
//        }
//    }
    
    for (int i=0; i<16; i++)
    {
        for (int j=0; j<30; j++)
        {
            cout << new_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n\n\n";
}


//void change_board(char board[16][30])   // 2nd board
//{
//    char arr[16][30];
//
//}




void print_board(char board[16][30])
{
    for (int i=0; i<16; i++)
    {
        for (int j=0; j<30; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    char board[16][30]={0};     // initialize all elements to null character
    make_board(board);
    print_board(board);
}
