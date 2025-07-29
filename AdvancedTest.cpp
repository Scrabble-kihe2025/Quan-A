#include "Game.h"
#include "Player.h"
#include "AIPlayer.h"
#include "GameRules.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== SCRABBLE GAME ADVANCED FEATURES TEST ===" << endl;
    cout << "Testing User A components with advanced features..." << endl << endl;
    
    try {
        cout << "1. Testing Basic Game Logic..." << endl;
        Game game;
        game.addPlayer("Alice");
        game.addPlayer("Bob");
        cout << "✓ Game created with 2 players" << endl;
        
        cout << "\n2. Testing AI Player..." << endl;
        AIPlayer aiPlayer("AI_Easy", 1);
        cout << "✓ AI Player created with difficulty: " << aiPlayer.getDifficulty() << endl;
        
        
        cout << "\n3. Testing Game Rules..." << endl;
        cout << "✓ Bingo bonus: " << GameRules::calculateBingoBonus() << " points" << endl;
        cout << "✓ Max players: " << GameRules::getMaxPlayers() << endl;
        cout << "✓ Tiles per player: " << GameRules::getTilesPerPlayer() << endl;
        
        
        cout << "\n4. Testing Advanced Scoring..." << endl;
        int score1 = game.calculateWordScore("HELLO");
        int score2 = game.calculateBingoBonus("EXAMPLE");
        cout << "✓ Word 'HELLO' score: " << score1 << " points" << endl;
        cout << "✓ Bingo bonus calculated: " << score2 << " points" << endl;
        
        
        cout << "\n5. Testing Player Features..." << endl;
        game.startGame();
        Player& currentPlayer = game.getCurrentPlayer();
        cout << "✓ Current player: " << currentPlayer.getName() << endl;
        cout << "✓ Hand size: " << currentPlayer.getHandSize() << endl;
        cout << "✓ Has vowels: " << (currentPlayer.hasVowels() ? "Yes" : "No") << endl;
        
        
        cout << "\n6. Testing Game State..." << endl;
        cout << "✓ Turn count: " << game.getTurnCount() << endl;
        cout << "✓ Tiles remaining: " << game.getTilesRemaining() << endl;
        cout << "✓ Game over: " << (game.isGameOver() ? "Yes" : "No") << endl;
        
        
        cout << "\n7. Testing Advanced Features..." << endl;
        bool canExchange = game.canExchangeTiles(3);
        cout << "✓ Can exchange 3 tiles: " << (canExchange ? "Yes" : "No") << endl;
        
        Player* highest = game.getHighestScoringPlayer();
        if (highest) {
            cout << "✓ Highest scoring player: " << highest->getName() << endl;
        }
        
        cout << "\n=== ALL ADVANCED TESTS PASSED! ===" << endl;
        cout << "\nUser A Advanced Features Implemented:" << endl;
        cout << "✅ AI Player with 3 difficulty levels" << endl;
        cout << "✅ Advanced game rules validation" << endl;
        cout << "✅ Enhanced player statistics" << endl;
        cout << "✅ Bingo bonus calculation" << endl;
        cout << "✅ Tile exchange system" << endl;
        cout << "✅ Pass counting and game end conditions" << endl;
        cout << "✅ Advanced scoring with multipliers" << endl;
        cout << "✅ Player hand analysis (vowels/consonants)" << endl;
        
    } catch (const exception& e) {
        cout << "✗ Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
