// Player class that keeps track of a single player and their pieces
// Player class implementation

#include <iostream>
#include "../include/Player.h"

// Display player's pieces and number of pieces left
void Player::displayPieces() {
    std::cout << std::endl;
    std::cout << "a. " << (piecesColor == 'Y' ? "YY" : "RR") << "  " << largePiecesCount << " remain." << std::endl;
    std::cout << "b. " << (piecesColor == 'Y' ? "Y" : "R") << "   " << midPiecesCount << " remain." << std::endl;
    std::cout << "c. " << (piecesColor == 'Y' ? "y" : "r") << "   " << smallPiecesCount << " remain." << std::endl;
    std::cout << "q to exit." << std::endl;
}

// Get a move from player, i.e the size of a piece and position
std::string Player::getPlayerMove() {
    std::string playerMove;
    do {
        std::cout << "\nIt is " << (piecesColor == 'Y' ? "yellow" : "red") << "'s turn." << std::endl;
        std::cout << "Choose action and location, for example a2: ";
        std::cin >> playerMove;
        if (!isMoveValid(playerMove)) {
            std::cout << "\nINVALID MOVE. TRY AGAIN \n";
        }
    } while (!isMoveValid(playerMove));
    return playerMove;
}

// Check if a player's move is valid
bool Player::isMoveValid(const std::string& playerMove) {
    if (playerMove == "q" || playerMove == "u") return true;

    if (playerMove.size() == 2) {
        char size = playerMove[0];
        char position = playerMove[1];
        if ((size == 'a' || size == 'b' || size == 'c') && (position >= '1' && position <= '9')) {
            return getPieceCount(size) > 0;
        }
    }
    return false;
}

// Update piece count
void Player::updatePieceCount(char size) {
    getPieceCount(size) -= 1;
}

// Get a player pieces color
char Player::getPieceColor() const {
    return piecesColor;
}

// Check if a player has any pieces left
bool Player::hasPiecesLeft() const {
    return largePiecesCount > 0 || midPiecesCount > 0 || smallPiecesCount > 0;
}

// Return the number of player's pieces left
int& Player::getPieceCount(char size) {
    switch (size) {
    case 'a': return largePiecesCount;
        break;
    case 'b': return midPiecesCount;
        break;
    case 'c': return smallPiecesCount;
        break;
    default: throw std::invalid_argument("Invalid piece size");
    }
}

// Check if the player has a larger piece to put
bool Player::hasLargerPiece(std::string piece) const {
    if (isupper(piece[1])) return false;
    if (isupper(piece[0])) return largePiecesCount > 0;
    if (islower(piece[0])) return midPiecesCount > 0 || largePiecesCount > 0;
    return false;
}