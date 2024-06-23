// Board class that keeps track of a game board state
// Header file that contains Board class declaration

#ifndef BOARD_H
#define BOARD_H

#include "Player.h"

class Board {
public:
    Board();
    void displayBoard() const;
    bool canPlacePiece(int position, const std::string& piece, char size);
    void placePiece(int position, const std::string& piece, char size);
    bool checkWin(const std::string& piece) const;
    bool checkTie(const Player& player1, const Player& player2) const;
    bool isFull() const;

private:
    std::string board[9];
};

#endif