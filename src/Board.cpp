// Board class that keeps track of a game board state
// Board class implementation

#include <iostream>
#include "../include/Board.h"

// Board class constructor
Board::Board() {
    for (int i = 0; i < 9; i++) {
        board[i] = " " + std::to_string(i + 1);
    }
}

// Display game board
void Board::displayBoard() const {
    std::cout << "\n\n"; //std::endl;
    std::string whitespace = "                  ";
    std::cout << whitespace << board[0] << "|" << board[1] << "|" << board[2] << "\n" << whitespace << "--------\n"
        << whitespace << board[3] << "|" << board[4] << "|" << board[5] << "\n" << whitespace << "--------\n"
        << whitespace << board[6] << "|" << board[7] << "|" << board[8] << std::endl;
    return;
}

// Check if the player can place a piece at a given position in the board
bool Board::canPlacePiece(int position, const std::string& piece, char size) {
    int pieceValue = (size == 'a') ? 3 : (size == 'b') ? 2 : 1;
    int currPieceVal = (board[position][0] == ' ') ? 0 : isupper(board[position][1]) ? 3 : isupper(board[position][0]) ? 2 : 1;

    if (pieceValue > currPieceVal) return true;
    return false;
}

// Place a piece at a given position
void Board::placePiece(int position, const std::string& piece, char size) {
    board[position] = size == 'a' ? piece : piece + std::to_string(position + 1);
    return;
}