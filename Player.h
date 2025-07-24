#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
private:
    std::string name;
    std::vector<char> hand;
    int score;
    static const int MAX_HAND_SIZE = 7;
    
public:
    Player();
    Player(const std::string& playerName);
    ~Player();
    
    const std::string& getName() const;
    int getScore() const;
    void addScore(int points);
    void setScore(int newScore);
    
    const std::vector<char>& getHand() const;
    int getHandSize() const;
    bool isHandFull() const;
    bool isHandEmpty() const;
    
    void addTileToHand(char tile);
    bool removeTileFromHand(char tile);
    void addTilesToHand(const std::vector<char>& tiles);
    std::vector<char> removeTilesFromHand(const std::vector<char>& tiles);
    void clearHand();
    
    bool hasTile(char tile) const;
    int countTile(char tile) const;
    std::vector<char> getAllTiles() const;
    
    bool canMakeMove() const;
    std::vector<char> exchangeTiles(const std::vector<char>& tilesToExchange, 
                                   const std::vector<char>& newTiles);
    
    void displayHand() const;
    void displayInfo() const;
    
    std::string handToString() const;
    void sortHand();
};

#endif
