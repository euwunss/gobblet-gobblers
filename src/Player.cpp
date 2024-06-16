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