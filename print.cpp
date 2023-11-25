#include <iostream>
#include <vector>
#include <algorithm>
#include "score.h" // Include the score.cpp file that contains the Score struct and related functions

using namespace std;

// Function to print out the scoreboard
void printScoreboard(const vector<Score>& scoreboard) {
    cout << "Scoreboard:" << endl;
    for (const Score& score : scoreboard) {
        cout << "Player: " << score.playerName << ", Score: " << score.record << endl;
    }
}

// Comparator function to sort scores in descending order
bool compareScores(const Score& score1, const Score& score2) {
    return score1.record > score2.record;
}

// Function to sort the scores from highest to lowest
void sortScores(vector<Score>& scoreboard) {
    sort(scoreboard.begin(), scoreboard.end(), compareScores);
}
