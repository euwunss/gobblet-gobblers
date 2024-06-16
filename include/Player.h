// Player class that keeps track of a single player and their pieces
// Header file that contains Player class declaration

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(char color) : isWinner(false), piecesColor(color), largePiecesCount(2), midPiecesCount(2), smallPiecesCount(2) {};
    void displayPieces();

private:
    bool isWinner;
    char piecesColor;
    int largePiecesCount;
    int midPiecesCount;
    int smallPiecesCount;
};

#endif