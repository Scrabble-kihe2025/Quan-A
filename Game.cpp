#include "Game.h"
#include "Player.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <iomanip>

Game::Game() : currentPlayerIndex(0), gameOver(false), turnCount(0) {
    initializeLetterValues();
    initializeTileBag();
}

Game::Game(const std::vector<std::string>& playerNames) : currentPlayerIndex(0), gameOver(false), turnCount(0) {
    initializeLetterValues();
    initializeTileBag();
    
    for (const std::string& name : playerNames) {
        addPlayer(name);
    }
}

Game::~Game() {
}

void Game::initializeLetterValues() {
    letterValues = {
        {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 4}, {'G', 2}, {'H', 4},
        {'I', 1}, {'J', 8}, {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1}, {'P', 3},
        {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8},
        {'Y', 4}, {'Z', 10}, {' ', 0}
    };
    
    letterCounts = {
        {'A', 9}, {'B', 2}, {'C', 2}, {'D', 4}, {'E', 12}, {'F', 2}, {'G', 3}, {'H', 2},
        {'I', 9}, {'J', 1}, {'K', 1}, {'L', 4}, {'M', 2}, {'N', 6}, {'O', 8}, {'P', 2},
        {'Q', 1}, {'R', 6}, {'S', 4}, {'T', 6}, {'U', 4}, {'V', 2}, {'W', 2}, {'X', 1},
        {'Y', 2}, {'Z', 1}, {' ', 2}
    };
}

void Game::initializeTileBag() {
    tileBag.clear();
    
    for (const auto& pair : letterCounts) {
        char letter = pair.first;
        int count = pair.second;
        
        for (int i = 0; i < count; i++) {
            tileBag.push_back(letter);
        }
    }
    
    shuffleTileBag();
}

void Game::shuffleTileBag() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(tileBag.begin(), tileBag.end(), g);
}

char Game::drawTileFromBag() {
    if (tileBag.empty()) {
        return '\0';
    }
    
    char tile = tileBag.back();
    tileBag.pop_back();
    return tile;
}

void Game::dealInitialTiles() {
    for (Player& player : players) {
        for (int i = 0; i < 7 && !tileBag.empty(); i++) {
            char tile = drawTileFromBag();
            if (tile != '\0') {
                player.addTileToHand(tile);
            }
        }
    }
}

void Game::addPlayer(const std::string& name) {
    if (players.size() < 4) {
        players.emplace_back(name);
    }
}

void Game::startGame() {
    if (players.size() < 2) {
        std::cout << "Need at least 2 players to start the game!" << std::endl;
        return;
    }
    
    gameOver = false;
    turnCount = 0;
    currentPlayerIndex = 0;
    
    for (Player& player : players) {
        player.setScore(0);
        player.clearHand();
    }
    
    initializeTileBag();
    dealInitialTiles();
    
    std::cout << "Game started with " << players.size() << " players!" << std::endl;
    displayGameState();
}

void Game::resetGame() {
    gameOver = false;
    turnCount = 0;
    currentPlayerIndex = 0;
    
    for (Player& player : players) {
        player.setScore(0);
        player.clearHand();
    }
    
    initializeTileBag();
    dealInitialTiles();
}

void Game::nextTurn() {
    if (!gameOver) {
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        turnCount++;
        
        if (getCurrentPlayer().isHandEmpty() || tileBag.empty()) {
            endGame();
        }
    }
}

bool Game::isGameOver() const {
    return gameOver;
}

int Game::getCurrentPlayerIndex() const {
    return currentPlayerIndex;
}

Player& Game::getCurrentPlayer() {
    return players[currentPlayerIndex];
}

const Player& Game::getCurrentPlayer() const {
    return players[currentPlayerIndex];
}

bool Game::hasMoreTiles() const {
    return !tileBag.empty();
}

std::vector<char> Game::drawTiles(int count) {
    std::vector<char> drawnTiles;
    
    for (int i = 0; i < count && !tileBag.empty(); i++) {
        char tile = drawTileFromBag();
        if (tile != '\0') {
            drawnTiles.push_back(tile);
        }
    }
    
    return drawnTiles;
}

void Game::returnTilesToBag(const std::vector<char>& tiles) {
    for (char tile : tiles) {
        tileBag.push_back(tile);
    }
    shuffleTileBag();
}

int Game::getLetterValue(char letter) const {
    auto it = letterValues.find(letter);
    return (it != letterValues.end()) ? it->second : 0;
}

int Game::calculateWordScore(const std::string& word, const std::vector<int>& multipliers) const {
    int score = 0;
    
    for (size_t i = 0; i < word.length(); i++) {
        int letterScore = getLetterValue(word[i]);
        
        if (i < multipliers.size()) {
            letterScore *= multipliers[i];
        }
        
        score += letterScore;
    }
    
    return score;
}

const std::vector<Player>& Game::getPlayers() const {
    return players;
}

int Game::getTurnCount() const {
    return turnCount;
}

int Game::getTilesRemaining() const {
    return tileBag.size();
}

Player* Game::getWinner() {
    if (!gameOver) {
        return nullptr;
    }
    
    Player* winner = &players[0];
    for (Player& player : players) {
        if (player.getScore() > winner->getScore()) {
            winner = &player;
        }
    }
    
    return winner;
}

void Game::endGame() {
    gameOver = true;
    
    std::cout << "\n=== GAME OVER ===" << std::endl;
    displayScores();
    
    Player* winner = getWinner();
    if (winner) {
        std::cout << "\nWinner: " << winner->getName() 
                  << " with " << winner->getScore() << " points!" << std::endl;
    }
}

void Game::displayGameState() const {
    std::cout << "\n=== SCRABBLE GAME ===" << std::endl;
    std::cout << "Turn: " << turnCount << std::endl;
    std::cout << "Tiles remaining: " << getTilesRemaining() << std::endl;
    std::cout << "Current player: " << getCurrentPlayer().getName() << std::endl;
    
    displayScores();
    displayCurrentPlayer();
}

void Game::displayScores() const {
    std::cout << "\n--- SCORES ---" << std::endl;
    for (const Player& player : players) {
        std::cout << player.getName() << ": " << player.getScore() << " points" << std::endl;
    }
}

void Game::displayCurrentPlayer() const {
    std::cout << "\n--- CURRENT PLAYER ---" << std::endl;
    getCurrentPlayer().displayInfo();
}
