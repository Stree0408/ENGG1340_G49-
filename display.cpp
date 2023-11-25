#include "display.h"
#include "mechanics.h"
#include <iostream>
using namespace std;

void displayBanner() {
    cout << "███╗░░░███╗██╗███╗░░██╗███████╗░██████╗░██╗░░░░░░░██╗███████╗███████╗██████╗░███████╗██████╗░\n"
            "████╗░████║██║████╗░██║██╔════╝██╔════╝░██║░░██╗░░██║██╔════╝██╔════╝██╔══██╗██╔════╝██╔══██╗\n"
            "██╔████╔██║██║██╔██╗██║█████╗░░╚█████╗░░╚██╗████╗██╔╝█████╗░░█████╗░░██████╔╝█████╗░░██████╔╝\n"
            "██║╚██╔╝██║██║██║╚████║██╔══╝░░░╚═══██╗░░████╔═████║░██╔══╝░░██╔══╝░░██╔═══╝░██╔══╝░░██╔══██╗\n"
            "██║░╚═╝░██║██║██║░╚███║███████╗██████╔╝░░╚██╔╝░╚██╔╝░███████╗███████╗██║░░░░░███████╗██║░░██║\n"
            "╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚══════╝╚═════╝░░░░╚═╝░░░╚═╝░░╚══════╝╚══════╝╚═╝░░░░░╚══════╝╚═╝░░╚═╝\n\n";
    
}

void mainMenu() {
    cout << "\n"
            "█▀█ █▀█ █▀▀ █▀ █▀   ▄█   ▀█▀ █▀█   █▀ ▀█▀ ▄▀█ █▀█ ▀█▀\n"
            "█▀▀ █▀▄ ██▄ ▄█ ▄█   ░█   ░█░ █▄█   ▄█ ░█░ █▀█ █▀▄ ░█░\n"
            "\n"
            "█▀█ █▀█ █▀▀ █▀ █▀   ▀█   ▀█▀ █▀█   █▀ █▀▀ █▀▀   █░░ █▀▀ ▄▀█ █▀▄ █▀▀ █▀█ █▄▄ █▀█ ▄▀█ █▀█ █▀▄\n"
            "█▀▀ █▀▄ ██▄ ▄█ ▄█   █▄   ░█░ █▄█   ▄█ ██▄ ██▄   █▄▄ ██▄ █▀█ █▄▀ ██▄ █▀▄ █▄█ █▄█ █▀█ █▀▄ █▄▀\n";

}

void displayControls() {
    cout << "\n"
            "┌───────────────────────────────────────────────────────────────────────────┐\n"
            "│ press W or A or S or D and press Enter for each move                      │\n"
            "│ if you put in multiple characters, only the first one will be considered  │\n"
            "│ press O and press Enter for uncovering the tile                           │\n"
            "│ press P and press Enter for flagging the tile                             │\n"
            "│ press M to end the game                                                   │\n"
            "│ @ means you uncovered a Mine                                              │\n"
            "│ if you uncover a Mine you will LOSE 100 points                            │\n"
            "│ FLAG all Mines to WIN!!                                                   │\n"
            "└───────────────────────────────────────────────────────────────────────────┘\n"
            "\n";
}

void displayFlags(int numberOfFlags) {
    cout << "Flags: " << numberOfFlags;
}
