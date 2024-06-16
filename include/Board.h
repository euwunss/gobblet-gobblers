// Board class that keeps track of a game board state
// Header file that contains Board class declaration

#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    void displayBoard() const;
    bool canPlacePiece(int position, const std::string& piece, char size);
    void placePiece(int position, const std::string& piece, char size);
    bool checkWin(const std::string& piece) const;

private:
    std::string board[9];
};

#endif