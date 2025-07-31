#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include <string>
#include <vector>
#include <map>

using namespace std;

struct WordPlayed {
    string word;
    int score;
    string playerName;
    int turnNumber;
};

class GameStatistics {
private:
    vector<WordPlayed> wordsPlayed;
    map<string, int> playerWordsCount;
    map<string, int> playerTotalScore;
    int totalTurns;
    int totalWordsPlayed;
    string highestScoringWord;
    int highestWordScore;
    string bestPlayer;
    
public:
    GameStatistics();
    void recordWord(const string& word, int score, const string& player, int turn);
    void updatePlayerStats(const string& player, int score);
    void calculateFinalStats();
    void displayStats() const;
    void displayPlayerStats(const string& player) const;
    int getAverageScore() const;
    string getHighestScoringWord() const;
    void reset();
};

#endif
