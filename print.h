#ifndef PRINT_H
#define PRINT_H

#include <vector>
#include "score.h" // Include the score.cpp file that contains the Score struct and related functions

// Function to print out the scoreboard
void printScoreboard(const std::vector<Score>& scoreboard);

// Function to sort the scores from highest to lowest
void sortScores(std::vector<Score>& scoreboard);

#endif // PRINT_H
