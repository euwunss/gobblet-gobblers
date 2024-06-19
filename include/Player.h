// Player class that keeps track of a single player and their pieces
// Header file that contains Player class declaration

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(char color) : piecesColor(color), largePiecesCount(2), midPiecesCount(2), smallPiecesCount(2) {};
    void displayPieces();
    std::string getPlayerMove();
    char getPieceColor() const;
    bool hasPiecesLeft() const;
    bool isMoveValid(const std::string& playerMove);
    void updatePieceCount(char size);
    int& getPieceCount(char size);

private:
    char piecesColor;
    int largePiecesCount;
    int midPiecesCount;
    int smallPiecesCount;
};

#endif