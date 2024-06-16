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