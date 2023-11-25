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
    b.numberOfFlags = 0;
    char input;

    // first input
    do {
        input = b.getPlayerInput(true);
    } while (input != 'o');

    // set the board using the first input, and reveal.
    b.placeMines();
    b.uncover(b.xLocation, b.yLocation);

    // running the rest of the game.
    do {
        input = b.getPlayerInput(false);
    } while (input != 'm');

    // needs a function to end the game and save the scores and stuff.
    cout << "game over";
    b.endGame();
    b.delDynamic();
}


int main() {
    displayBanner();
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
    else if (firstinput ==2) {
        leaderboard();
    return 0;
}
