#ifndef GAMERULES_H
#define GAMERULES_H

#include <string>
#include <vector>

using namespace std;

class GameRules {
private:
    static const int BINGO_BONUS = 50;
    static const int MINIMUM_WORD_LENGTH = 2;
    static const int MAXIMUM_PLAYERS = 4;
    static const int TILES_PER_PLAYER = 7;
    static const int PASS_LIMIT = 6;
    
public:
    static int calculateBingoBonus();
    static int getMinimumWordLength();
    static bool isValidWordLength(const string& word);
    
    static int getMaxPlayers();
    static int getTilesPerPlayer();
    static bool isValidPlayerCount(int count);
    
    static int getPassLimit();
    static bool isGameEndCondition(int consecutivePasses, int tilesRemaining, bool playerHandEmpty);
    
    static bool canExchangeTiles(int tilesInBag, int tilesToExchange);
    static bool canPass(int consecutivePasses);
    
    static int calculateEndGamePenalty(const vector<char>& remainingTiles);
    static int getLetterPenalty(char letter);
    
    static bool validateMove(const string& word, const vector<char>& playerHand);
    static vector<char> getRequiredTiles(const string& word);
};
