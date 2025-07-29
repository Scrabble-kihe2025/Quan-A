#include "Game.h"
#include "Player.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Testing Scrabble Components..." << endl;
    
    try {
        Game game;
        cout << "✓ Game object created successfully" << endl;
        
        game.addPlayer("Alice");
        game.addPlayer("Bob");
        cout << "✓ Players added successfully" << endl;
        
        game.startGame();
        cout << "✓ Game started successfully" << endl;
        
        Player& currentPlayer = game.getCurrentPlayer();
        cout << "✓ Current player: " << currentPlayer.getName() << endl;
        
        int score = game.calculateWordScore("HELLO");
        cout << "✓ Word score calculation: HELLO = " << score << " points" << endl;
        
        cout << "\n=== All tests passed! ===" << endl;
        
    } catch (const exception& e) {
        cout << "✗ Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
