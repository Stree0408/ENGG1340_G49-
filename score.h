#ifndef score_H
#define score_H

#include <string>
#include <vector>

struct Score {
    std::string playerName;
    int record;
};

void saveScoreboard(const std::vector<Score>& scoreboard);
void updateScoreboard(const std::string& playerName, int points);
void loadScoreboard(std::vector<Score>& scoreboard);

#endif

