#include "AIPlayer.h"
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

AIPlayer::AIPlayer(const string& name, int difficulty) 
    : Player(name), difficultyLevel(difficulty) {
}

string AIPlayer::makeMove(const Game& game) {
    vector<string> possibleWords = generatePossibleWords();
    
    if (possibleWords.empty()) {
        return "";
    }
    
    string bestWord = "";
    int bestScore = 0;
    
    for (const string& word : possibleWords) {
        int potential = calculateWordPotential(word, game);
        if (potential > bestScore) {
            bestScore = potential;
            bestWord = word;
        }
    }
    
    return bestWord;
}

vector<string> AIPlayer::generatePossibleWords() const {
    vector<string> words;
    
    vector<char> hand = getAllTiles();
    
    for (size_t i = 0; i < hand.size(); i++) {
        for (size_t j = i + 1; j < hand.size(); j++) {
            string word = "";
            word += hand[i];
            word += hand[j];
            words.push_back(word);
        }
    }
    
    if (hand.size() >= 3) {
        for (size_t i = 0; i < hand.size(); i++) {
            for (size_t j = i + 1; j < hand.size(); j++) {
                for (size_t k = j + 1; k < hand.size(); k++) {
                    string word = "";
                    word += hand[i];
                    word += hand[j]; 
                    word += hand[k];
                    words.push_back(word);
                }
            }
        }
    }
    
    return words;
}

int AIPlayer::calculateWordPotential(const string& word, const Game& game) const {
    int baseScore = game.calculateWordScore(word);
    
    switch (difficultyLevel) {
        case 1: 
            return baseScore + (rand() % 5 - 2);
        case 2: 
            return baseScore + (word.length() * 2);
        case 3: 
            return baseScore + (word.length() * 3) + (word.find('Q') != string::npos ? 10 : 0);
        default:
            return baseScore;
    }
}

bool AIPlayer::shouldExchangeTiles(const Game& game) const {
    vector<char> hand = getAllTiles();
    int lowValueTiles = 0;
    
    for (char tile : hand) {
        if (game.getLetterValue(tile) <= 1) {
            lowValueTiles++;
        }
    }
    
    return (lowValueTiles > (int)(hand.size() / 2)) && game.hasMoreTiles();
}

vector<char> AIPlayer::chooseTilesToExchange() const {
    vector<char> hand = getAllTiles();
    vector<char> toExchange;
    
    for (char tile : hand) {
        if (tile == 'A' || tile == 'E' || tile == 'I' || tile == 'O' || tile == 'U') {
            if (toExchange.size() < 3) {
                toExchange.push_back(tile);
            }
        }
    }
    
    return toExchange;
}

void AIPlayer::setDifficulty(int level) {
    if (level >= 1 && level <= 3) {
        difficultyLevel = level;
    }
}

int AIPlayer::getDifficulty() const {
    return difficultyLevel;
}

void AIPlayer::displayInfo() const {
    Player::displayInfo();
    string difficulty;
    switch (difficultyLevel) {
        case 1: difficulty = "De"; break;
        case 2: difficulty = "Trung binh"; break;
        case 3: difficulty = "Kho"; break;
        default: difficulty = "Khong ro"; break;
    }
    cout << "Do kho AI: " << difficulty << endl;
}
