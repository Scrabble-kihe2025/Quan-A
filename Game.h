#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <map>

class Player;

class Game {
private:
    std::vector<Player> players;
    int currentPlayerIndex;
    std::vector<char> tileBag;
    std::map<char, int> letterValues;
    std::map<char, int> letterCounts;
    bool gameOver;
    int turnCount;
    
    void initializeTileBag();
    void initializeLetterValues();
    void shuffleTileBag();
    char drawTileFromBag();
    void dealInitialTiles();
    
public:
    Game();
    Game(const std::vector<std::string>& playerNames);
    ~Game();
    
    void addPlayer(const std::string& name);
    void startGame();
    void resetGame();
    
    void nextTurn();
    bool isGameOver() const;
    int getCurrentPlayerIndex() const;
    Player& getCurrentPlayer();
    const Player& getCurrentPlayer() const;
    
    bool hasMoreTiles() const;
    std::vector<char> drawTiles(int count);
    void returnTilesToBag(const std::vector<char>& tiles);
    
    int getLetterValue(char letter) const;
    int calculateWordScore(const std::string& word, const std::vector<int>& multipliers = {}) const;
    
    const std::vector<Player>& getPlayers() const;
    int getTurnCount() const;
    int getTilesRemaining() const;
    
    Player* getWinner();
    void endGame();
    
    void displayGameState() const;
    void displayScores() const;
    void displayCurrentPlayer() const;
};

#endif
