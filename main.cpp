#include "board.h"
#include "colors.h"
#include "display.h"
#include <iostream>
using namespace std;

int main() {
    Board b;
    b.setBoardSize();

    // first input
    do {
        b.getPlayerInput(true);
    } while (b.getPlayerInput(true) != 'o');

    // set the board using the first input, and reveal.
    b.setBoard();
    b.uncover(b.xLocation, b.yLocation);

    // running the rest of the game.
    do {
        b.getPlayerInput(false);
    } while (b.getPlayerInput(false) != 'm');

    // needs a function to end the game and save the scores and stuff.
    cout << "game over";
    return 0;
}
