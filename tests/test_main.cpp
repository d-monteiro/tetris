#include <iostream>
#include <cassert>
#include "../include/pieces.hpp"
#include "../include/board.hpp"

// Test function declarations
void test_pieces();
void test_board();

int main() {
    std::cout << "Running Tetris tests..." << std::endl;
    
    try {
        test_pieces();
        test_board();
        
        std::cout << "All tests passed!" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}

// Test the pieces functionality
void test_pieces() {
    std::cout << "Testing pieces..." << std::endl;
    
    // Create pieces object
    Pieces pieces;
    
    // Test piece block types
    // Square piece (0) first rotation (0)
    assert(pieces.GetBlockType(0, 0, 2, 2) == 2); // Pivot block
    assert(pieces.GetBlockType(0, 0, 3, 2) == 1); // Regular block
    assert(pieces.GetBlockType(0, 0, 2, 3) == 1); // Regular block
    assert(pieces.GetBlockType(0, 0, 3, 3) == 1); // Regular block
    assert(pieces.GetBlockType(0, 0, 0, 0) == 0); // Empty space
    
    // Test initial positions
    assert(pieces.GetXInitialPosition(0, 0) == -2); // For square piece
    assert(pieces.GetYInitialPosition(0, 0) == -3); // For square piece
    
    std::cout << "Pieces tests passed!" << std::endl;
}

// Test the board functionality
void test_board() {
    std::cout << "Testing board..." << std::endl;
    
    // Create necessary objects
    Pieces pieces;
    Board board(&pieces, 600); // Assuming screen height is 600
    
    // Test initial board state
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            assert(board.IsFreeBlock(i, j) == true); // All blocks should be free
        }
    }
    
    // Store a square piece at position (5,5)
    board.StorePiece(5, 5, 0, 0); 
    
    // Check that the blocks are now filled
    // The square piece has blocks at local positions (2,2), (3,2), (2,3), (3,3)
    // So when stored at (5,5), they fill positions (7,7), (8,7), (7,8), (8,8)
    assert(board.IsFreeBlock(7, 7) == false); // Pivot
    assert(board.IsFreeBlock(8, 7) == false); // Right of pivot
    assert(board.IsFreeBlock(7, 8) == false); // Below pivot
    assert(board.IsFreeBlock(8, 8) == false); // Diagonal from pivot
    
    // Check that other areas are still free
    assert(board.IsFreeBlock(6, 7) == true);
    assert(board.IsFreeBlock(9, 7) == true);
    
    // Test movement validation
    // Testing if we can place another piece at (5,5) - should cause collision
    assert(board.IsPossibleMovement(6, 6, 0, 0) == false); // Collision with stored piece
    
    std::cout << "Board tests passed!" << std::endl;
}