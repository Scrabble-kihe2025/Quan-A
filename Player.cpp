#include "Player.h"
#include <iostream>
#include <algorithm>
#include <sstream>

Player::Player() : name("Unknown"), score(0) {
}

Player::Player(const std::string& playerName) : name(playerName), score(0) {
}

Player::~Player() {
}

const std::string& Player::getName() const {
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

const std::vector<char>& Player::getHand() const {
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
    auto it = std::find(hand.begin(), hand.end(), tile);
    if (it != hand.end()) {
        hand.erase(it);
        return true;
    }
    return false;
}

void Player::addTilesToHand(const std::vector<char>& tiles) {
    for (char tile : tiles) {
        addTileToHand(tile);
    }
}

std::vector<char> Player::removeTilesFromHand(const std::vector<char>& tiles) {
    std::vector<char> removedTiles;
    
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
    return std::find(hand.begin(), hand.end(), tile) != hand.end();
}

int Player::countTile(char tile) const {
    return std::count(hand.begin(), hand.end(), tile);
}

std::vector<char> Player::getAllTiles() const {
    return hand;
}

bool Player::canMakeMove() const {
    return !isHandEmpty();
}

std::vector<char> Player::exchangeTiles(const std::vector<char>& tilesToExchange, 
                                       const std::vector<char>& newTiles) {
    std::vector<char> exchangedTiles = removeTilesFromHand(tilesToExchange);
    addTilesToHand(newTiles);
    return exchangedTiles;
}

void Player::displayHand() const {
    std::cout << "Hand: ";
    if (hand.empty()) {
        std::cout << "(empty)";
    } else {
        for (size_t i = 0; i < hand.size(); i++) {
            if (i > 0) std::cout << " ";
            if (hand[i] == ' ') {
                std::cout << "?";
            } else {
                std::cout << hand[i];
            }
        }
    }
    std::cout << " (" << hand.size() << "/" << MAX_HAND_SIZE << ")" << std::endl;
}

void Player::displayInfo() const {
    std::cout << "Player: " << name << std::endl;
    std::cout << "Score: " << score << std::endl;
    displayHand();
}

std::string Player::handToString() const {
    std::ostringstream oss;
    for (size_t i = 0; i < hand.size(); i++) {
        if (i > 0) oss << " ";
        if (hand[i] == ' ') {
            oss << "?";
        } else {
            oss << hand[i];
        }
    }
    return oss.str();
}

void Player::sortHand() {
    std::sort(hand.begin(), hand.end());
}
