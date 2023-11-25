#include <iostream>
#include <fstream>
#include <vector>
#include "score.h"

using namespace std;



void loadScoreboard(vector<Score>& scoreboard);

void saveScoreboard(const vector<Score>& scoreboard) {
    ofstream file("scoreboard.txt");
    if (file.is_open()) {
        for (const Score& score : scoreboard) {
            file << score.playerName << " " << score.record << endl;
        }
        file.close();
    } else {
        cout << "Unable to open the scoreboard file." << endl;
    }
}

void updateScoreboard(const string& playerName, int points) {
    vector<Score> scoreboard;
    loadScoreboard(scoreboard);

    Score score;
    score.playerName = playerName;
    score.record = points;

    scoreboard.push_back(score);
    saveScoreboard(scoreboard);
}

void loadScoreboard(vector<Score>& scoreboard) {
    ifstream file("scoreboard.txt");
    if (file.is_open()) {
        Score score;
        while (file >> score.playerName >> score.record) {
            scoreboard.push_back(score);
        }
        file.close();
    } else {
        cout << "No previously saved scoreboard file found. Your score will be recorded on a new scoreboard." << endl;
    }
}

int scoring() {
    string playerName;
    int points;

    cout << "Enter player name: ";
    cin >> playerName;

    cout << "Enter points: ";
    cin >> points;

    updateScoreboard(playerName, points);

    return 0;
}
