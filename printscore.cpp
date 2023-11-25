#include <iostream>
#include <vector>
#include <algorithm>
#include "score.cpp" // Include the score.cpp file that contains the Score struct and related functions

using namespace std;

// Function to print out the scoreboard
void printScoreboard(const vector<Score>& scoreboard) {
    cout << "Scoreboard:" << endl;
    for (const Score& score : scoreboard) {
        cout << "Player: " << score.playerName << ", Score: " << score.score << endl;
    }
}

// Comparator function to sort scores in descending order
bool compareScores(const Score& score1, const Score& score2) {
    return score1.score > score2.score;
}

// Function to sort the scores from highest to lowest
void sortScores(vector<Score>& scoreboard) {
    sort(scoreboard.begin(), scoreboard.end(), compareScores);
}

int printingscore() {
    vector<Score> scoreboard;
    loadScoreboard(scoreboard);

    // Print the unsorted scoreboard
    printScoreboard(scoreboard);

    // Sort the scoreboard
    sortScores(scoreboard);

    // Print the sorted scoreboard
    cout << "Sorted Scoreboard:" << endl;
    printScoreboard(scoreboard);

    return 0;
}
