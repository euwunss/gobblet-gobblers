#include <iostream>
#include <string>
#include <vector>

#include "../include/Board.h"
#include "../include/Player.h"

int main() {
	std::cout << "\n*********** GOBBLET AND GOBBLERS  ***********\n";

	// Create a board and two players
	Board board;
	Player player1('Y'), player2('R');
	Player* currentPlayer = &player1;
	bool gameRunning = true;

	// Continue the game until one player wins or both players run out of their pieces
	while (gameRunning && (player1.hasPiecesLeft() || player2.hasPiecesLeft())) {
		// Display the board and player's pieces
		board.displayBoard();
		currentPlayer->displayPieces();

		// Get a player's move and exit game if the input is 'q'
		std::string playerMove = currentPlayer->getPlayerMove();
		if (playerMove == "q") return 0;

		char pieceSize = playerMove[0];
		int position = playerMove[1] - '1';
		std::string piece = (pieceSize == 'a') ? (currentPlayer->getPieceColor() == 'Y' ? "YY" : "RR") : (pieceSize == 'b') ? std::string(1, toupper(currentPlayer->getPieceColor())) : std::string(1, tolower(currentPlayer->getPieceColor()));

		if (board.canPlacePiece(position, piece, pieceSize)) {
			board.placePiece(position, piece, pieceSize);
			currentPlayer->updatePieceCount(pieceSize);

			// Print a winner if there is one
			if (board.checkWin(piece)) {
				board.displayBoard();
				std::cout << (currentPlayer->getPieceColor() == 'Y' ? "\nYellow Wins!" : "\nRed Wins!") << std::endl;
				gameRunning = false;
			}
			// Tie game if both players run out of pieces
			else if (!player1.hasPiecesLeft() && !player2.hasPiecesLeft()) {
				board.displayBoard();
				std::cout << "\nTie game." << std::endl;
				gameRunning = false;
			}
			// Turn of another player
			else {
				currentPlayer = currentPlayer == &player1 ? &player2 : &player1;
			}
			
		}
		else {
			std::cout << "Invalid move. Try again." << std::endl;
		}
	}

	return 0;
}

