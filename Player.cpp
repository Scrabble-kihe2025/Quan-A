

#include "Player.h"
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

Player::Player() : name("Unknown"), score(0) {
}

Player::Player(const string& playerName) : name(playerName), score(0) {
}

Player::~Player() {
}

const string& Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

void Player::addScore(int points) {
    score += points;
    if (score < 0) score = 0;
}

void Player::setScore(int newScore) {
    score = (newScore >= 0) ? newScore : 0;
}

const vector<char>& Player::getHand() const {
    return hand;
}

int Player::getHandSize() const {
    return hand.size();
}

bool Player::isHandFull() const {
    return hand.size() >= MAX_HAND_SIZE;
}

bool Player::isHandEmpty() const {
    return hand.empty();
}

void Player::addTileToHand(char tile) {
    if (!isHandFull()) {
        hand.push_back(tile);
        sortHand();
    }
}

bool Player::removeTileFromHand(char tile) {
    auto it = find(hand.begin(), hand.end(), tile);
    if (it != hand.end()) {
        hand.erase(it);
        return true;
    }
    return false;
}

void Player::addTilesToHand(const vector<char>& tiles) {
    for (char tile : tiles) {
        addTileToHand(tile);
    }
}

vector<char> Player::removeTilesFromHand(const vector<char>& tiles) {
    vector<char> removedTiles;
    
    for (char tile : tiles) {
        if (removeTileFromHand(tile)) {
            removedTiles.push_back(tile);
        }
    }
    
    return removedTiles;
}

void Player::clearHand() {
    hand.clear();
}

bool Player::hasTile(char tile) const {
    return find(hand.begin(), hand.end(), tile) != hand.end();
}

int Player::countTile(char tile) const {
    return count(hand.begin(), hand.end(), tile);
}

vector<char> Player::getAllTiles() const {
    return hand;
}

bool Player::canMakeMove() const {
    return !isHandEmpty();
}

vector<char> Player::exchangeTiles(const vector<char>& tilesToExchange, 
                                       const vector<char>& newTiles) {
    vector<char> exchangedTiles = removeTilesFromHand(tilesToExchange);
    addTilesToHand(newTiles);
    return exchangedTiles;
}

void Player::displayHand() const {
    cout << "Hand: ";
    if (hand.empty()) {
        cout << "(empty)";
    } else {
        for (int i = 0; i < hand.size(); i++) {
            if (i > 0) cout << " ";
            if (hand[i] == ' ') {
                cout << "?";
            } else {
                cout << hand[i];
            }
        }
    }
    cout << " (" << hand.size() << "/" << MAX_HAND_SIZE << ")" << endl;
}

void Player::displayInfo() const {
    cout << "Player: " << name << endl;
    cout << "Score: " << score << endl;
    displayHand();
}

string Player::handToString() const {
    string result = "";
    for (int i = 0; i < hand.size(); i++) {
        if (i > 0) result += " ";
        if (hand[i] == ' ') {
            result += "?";
        } else {
            result += hand[i];
        }
    }
    return result;
}

void Player::sortHand() {
    sort(hand.begin(), hand.end());
}

bool Player::hasVowels() const {
    for (char tile : hand) {
        if (tile == 'A' || tile == 'E' || tile == 'I' || tile == 'O' || tile == 'U') {
            return true;
        }
    }
    return false;
}
