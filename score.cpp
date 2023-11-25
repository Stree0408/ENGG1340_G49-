#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Score {
    string playerName;
    int record;
};

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

void updateScoreboard(const string& playerName, int points, vector<Score>& scoreboard) {
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
        cout << "No scoreboard file found. Starting a new game." << endl;
    }
}

int scoring() {
    vector<Score> scoreboard;
    loadScoreboard(scoreboard);

    string playerName;
    int points;

    cout << "Enter player name: ";
    cin >> playerName;

    cout << "Enter points: ";
    cin >> points;

    updateScoreboard(playerName, points, scoreboard);

    // Ask the user whether to continue from the previous game or start new
    cout << "Do you want to continue from the previous game? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        // Continue from the previous game
        if (scoreboard.empty()) {
            cout << "No scores found. Starting a new game." << endl;
        } else {
            for (const Score& record : scoreboard) {
                cout << "Player: " << record.playerName << ", Score: " << record.record << endl;
            }
        }
    } else {
        // Start a new game
        scoreboard.clear();
        saveScoreboard(scoreboard);
    }

    return 0;
}

int main() {
    scoring();
    return 0;
}
