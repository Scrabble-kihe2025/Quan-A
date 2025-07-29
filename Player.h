

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

using namespace std;

class Player {
private:
    string name;
    vector<char> hand;
    int score;
    static const int MAX_HAND_SIZE = 7;
    
public:
    Player();
    Player(const string& playerName);
    virtual ~Player();
    
    const string& getName() const;
    int getScore() const;
    void addScore(int points);
    void setScore(int newScore);
    
    const vector<char>& getHand() const;
    int getHandSize() const;
    bool isHandFull() const;
    bool isHandEmpty() const;
    
    void addTileToHand(char tile);
    bool removeTileFromHand(char tile);
    void addTilesToHand(const vector<char>& tiles);
    vector<char> removeTilesFromHand(const vector<char>& tiles);
    void clearHand();
    
    bool hasTile(char tile) const;
    int countTile(char tile) const;
    vector<char> getAllTiles() const;
    bool hasVowels() const;
    
    bool canMakeMove() const;
    vector<char> exchangeTiles(const vector<char>& tilesToExchange, 
                                   const vector<char>& newTiles);
    
    void displayHand() const;
    virtual void displayInfo() const;
    
    string handToString() const;
    void sortHand();
};

#endif
