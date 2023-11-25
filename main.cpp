#include "display.h"
#include "mechanics.h"
#include <iostream>
using namespace std;

void runGame() {
    Board b;
    b.setBoardSize();
    b.setBoard();
    b.xLocation = 3;
    b.yLocation = 3;
    b.currentScore = 5000;

    // first input
    do {
        b.getPlayerInput(true);
    } while (b.getPlayerInput(true) != 'o');

    // set the board using the first input, and reveal.
    b.placeMines();
    b.uncover(b.xLocation, b.yLocation);

    // running the rest of the game.
    do {
        b.getPlayerInput(false);
    } while (b.getPlayerInput(false) != 'm');

    // needs a function to end the game and save the scores and stuff.
    cout << "game over";
    b.delDynamic();
}


int main() {
    mainMenu();
    int firstinput;
    cin >> firstinput;
    while (firstinput != 1 && firstinput != 2) {
    cout << "Please enter the number again: ";
    cin >> firstinput;
    }
    if(firstinput == 1){
    runGame();} 
    // need function for leaderboard
    return 0;
}
