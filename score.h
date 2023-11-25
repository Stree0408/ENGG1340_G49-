#ifndef score_H
#define score_H
#include <vector>
#include <string>
#include <vector>

struct Score {
    std::string playerName;
    int record;
};

void saveScoreboard(const std::vector<Score>& scoreboard);
void updateScoreboard(const std::string& playerName, int points);
void loadScoreboard(std::vector<Score>& scoreboard);
 // Include the score.cpp file that contains the Score struct and related functions

// Function to print out the scoreboard
void printScoreboard(const std::vector<Score>& scoreboard);

// Function to sort the scores from highest to lowest
void sortScores(std::vector<Score>& scoreboard);
#endif

