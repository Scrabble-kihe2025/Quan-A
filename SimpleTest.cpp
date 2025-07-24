#include "Game.h"
#include "Player.h"
#include <iostream>

int main() {
    std::cout << "Testing Scrabble Components..." << std::endl;
    
    try {
        Game game;
        std::cout << "✓ Game object created successfully" << std::endl;
        
        game.addPlayer("Alice");
        game.addPlayer("Bob");
        std::cout << "✓ Players added successfully" << std::endl;
        
        game.startGame();
        std::cout << "✓ Game started successfully" << std::endl;
        
        Player& currentPlayer = game.getCurrentPlayer();
        std::cout << "✓ Current player: " << currentPlayer.getName() << std::endl;
        
        int score = game.calculateWordScore("HELLO");
        std::cout << "✓ Word score calculation: HELLO = " << score << " points" << std::endl;
        
        std::cout << "\n=== All tests passed! ===" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✗ Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
