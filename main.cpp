#include <iostream>
#include "Player.h"
#include "Game.h"
#include "AIPlayer.h"
#include "GameRules.h"

using namespace std;

int main()
{
    cout << "=== TESTING ALL CLASSES IN SRC FOLDER ===" << endl;

    // Test Player Class
    cout << "\n1. TESTING PLAYER CLASS:" << endl;
    Player p1("Quan");
    cout << "Player created: " << p1.getName() << endl;
    cout << "Initial score: " << p1.getScore() << endl;

    p1.addTileToHand('A');
    p1.addTileToHand('B');
    p1.addTileToHand('C');
    cout << "Hand size after adding A,B,C: " << p1.getHandSize() << endl;

    p1.addScore(25);
    cout << "Score after adding 25: " << p1.getScore() << endl;
    cout << "Has vowels: " << (p1.hasVowels() ? "Yes" : "No") << endl;
    p1.displayInfo();

    // Test Game Class
    cout << "\n2. TESTING GAME CLASS:" << endl;
    Game game;
    game.addPlayer("Alice");
    game.addPlayer("Bob");
    cout << "Game created with 2 players" << endl;
    cout << "Current player index: " << game.getCurrentPlayerIndex() << endl;
    cout << "Is game over: " << (game.isGameOver() ? "Yes" : "No") << endl;

    // Test AIPlayer Class
    cout << "\n3. TESTING AI PLAYER CLASS:" << endl;
    AIPlayer ai("AI_Bot", 2);
    cout << "AI Player name: " << ai.getName() << endl;
    cout << "AI Difficulty: " << ai.getDifficulty() << endl;
    ai.displayInfo();

    // Test GameRules Class
    cout << "\n4. TESTING GAME RULES CLASS:" << endl;
    cout << "Bingo bonus: " << GameRules::calculateBingoBonus() << " points" << endl;
    cout << "Max players: " << GameRules::getMaxPlayers() << endl;
    cout << "Tiles per player: " << GameRules::getTilesPerPlayer() << endl;
    cout << "Minimum word length: " << GameRules::getMinimumWordLength() << endl;
    cout << "Pass limit: " << GameRules::getPassLimit() << endl;

    cout << "\n=== ALL TESTS COMPLETED SUCCESSFULLY! ===" << endl;

    return 0;
}
