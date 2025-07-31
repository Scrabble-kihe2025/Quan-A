#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <map>

using namespace std;

class Player;

class Game {
private:
    vector<Player> players;
    int currentPlayerIndex;
    vector<char> tileBag;
    map<char, int> letterValues;
    map<char, int> letterCounts;
    bool gameOver;
    int turnCount;
    
    void initializeTileBag();
    void initializeLetterValues();
    void shuffleTileBag();
    char drawTileFromBag();
    void dealInitialTiles();
    
public:
    Game();
    Game(const vector<string>& playerNames);
    ~Game();
    
    void addPlayer(const string& name);
    void startGame();
    void resetGame();
    
    void nextTurn();
    bool isGameOver() const;
    int getCurrentPlayerIndex() const;
    Player& getCurrentPlayer();
    const Player& getCurrentPlayer() const;
    
    bool hasMoreTiles() const;
    vector<char> drawTiles(int count);
    void returnTilesToBag(const vector<char>& tiles);
    
    int getLetterValue(char letter) const;
    int calculateWordScore(const string& word, const vector<int>& multipliers = {}) const;
    
    const vector<Player>& getPlayers() const;
    int getTurnCount() const;
    int getTilesRemaining() const;
    
    Player* getWinner();
    void endGame();
    
    void displayGameState() const;
    void displayScores() const;
    void displayCurrentPlayer() const;
    
    bool validateWord(const string& word) const;
    int calculateBingoBonus(const string& word) const;
    void handlePass();
    bool canExchangeTiles(int count) const;
    vector<char> exchangePlayerTiles(int playerIndex, const vector<char>& tilesToExchange);
    
    int getConsecutivePasses() const;
    Player* getHighestScoringPlayer() const;
    Player* getLowestScoringPlayer() const;
    int getAverageScore() const;
    int getTotalTilesInPlay() const;
    
    int calculateEndGameBonus(int playerIndex) const;
    void applyEndGamePenalties();
    int getMaxPossibleScore(const vector<char>& tiles) const;
    
private:
    int consecutivePasses;
    vector<int> wordHistory;
    void incrementPassCount();
    void resetPassCount();
};

#endif
