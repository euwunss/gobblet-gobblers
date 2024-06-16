// Board class that keeps track of a game board state
// Header file that contains Board class declaration

#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    void displayBoard() const;

private:
    std::string board[9];
};

#endif