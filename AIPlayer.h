#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"
#include "Game.h"
#include <vector>
#include <string>

using namespace std;

class AIPlayer : public Player {
private:
    int difficultyLevel;
    
    string findBestWord(const Game& game) const;
    int calculateWordPotential(const string& word, const Game& game) const;
    vector<string> generatePossibleWords() const;
    
public:
    AIPlayer(const string& name, int difficulty = 2);
    
    string makeMove(const Game& game);
    bool shouldExchangeTiles(const Game& game) const;
    vector<char> chooseTilesToExchange() const;
    
    void setDifficulty(int level);
    int getDifficulty() const;
    
    void displayInfo() const override;
};
