#include "GameRules.h"
#include <algorithm>
#include <map>

using namespace std;

int GameRules::calculateBingoBonus() {
    return BINGO_BONUS;
}

int GameRules::getMinimumWordLength() {
    return MINIMUM_WORD_LENGTH;
}

bool GameRules::isValidWordLength(const string& word) {
    return word.length() >= MINIMUM_WORD_LENGTH;
}

int GameRules::getMaxPlayers() {
    return MAXIMUM_PLAYERS;
}

int GameRules::getTilesPerPlayer() {
    return TILES_PER_PLAYER;
}

bool GameRules::isValidPlayerCount(int count) {
    return count >= 2 && count <= MAXIMUM_PLAYERS;
}

int GameRules::getPassLimit() {
    return PASS_LIMIT;
}

bool GameRules::isGameEndCondition(int consecutivePasses, int tilesRemaining, bool playerHandEmpty) {
    return consecutivePasses >= PASS_LIMIT || 
           (tilesRemaining == 0 && playerHandEmpty);
}

bool GameRules::canExchangeTiles(int tilesInBag, int tilesToExchange) {
    return tilesInBag >= tilesToExchange && tilesToExchange > 0 && tilesToExchange <= TILES_PER_PLAYER;
}

bool GameRules::canPass(int consecutivePasses) {
    return consecutivePasses < PASS_LIMIT;
}

int GameRules::calculateEndGamePenalty(const vector<char>& remainingTiles) {
    int penalty = 0;
    for (char tile : remainingTiles) {
        penalty += getLetterPenalty(tile);
    }
    return penalty;
}

int GameRules::getLetterPenalty(char letter) {
    static map<char, int> penalties = {
        {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 4}, {'G', 2}, {'H', 4},
        {'I', 1}, {'J', 8}, {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1}, {'P', 3},
        {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8},
        {'Y', 4}, {'Z', 10}, {' ', 0}
    };
    
    auto it = penalties.find(letter);
    return (it != penalties.end()) ? it->second : 0;
}

bool GameRules::validateMove(const string& word, const vector<char>& playerHand) {
    if (!isValidWordLength(word)) {
        return false;
    }
    
    vector<char> requiredTiles = getRequiredTiles(word);
    vector<char> handCopy = playerHand;
    
    for (char tile : requiredTiles) {
        auto it = find(handCopy.begin(), handCopy.end(), tile);
        if (it != handCopy.end()) {
            handCopy.erase(it);
        } else {
            auto blankIt = find(handCopy.begin(), handCopy.end(), ' ');
            if (blankIt != handCopy.end()) {
                handCopy.erase(blankIt);
            } else {
                return false;
            }
        }
    }
    
    return true;
}

vector<char> GameRules::getRequiredTiles(const string& word) {
    vector<char> tiles;
    for (char c : word) {
        if (c >= 'A' && c <= 'Z') {
            tiles.push_back(c);
        }
    }
    return tiles;
}
