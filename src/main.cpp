#include <iostream>
#include <string>
#include <vector>

#include "../include/Board.h"
#include "../include/Player.h"
#include "../include/BoardStack.h"

int main() {
	std::cout << "\n*********** GOBBLET AND GOBBLERS  ***********\n";

	// Create a board and two players
	Board board;
	BoardStack boardStack;
	Player player1('Y'), player2('R');
	Player* currentPlayer = &player1;
	bool gameRunning = true;
	bool showBoard = true;

	// Continue the game until one player wins or both players run out of their pieces
	while (gameRunning) {

		// Display the board and player's pieces
		if (showBoard) {
			board.displayBoard();
			currentPlayer->displayPieces();
		}
		showBoard = true;

		// Get a player's move and exit game if the input is 'q'
		std::string playerMove = currentPlayer->getPlayerMove();
		if (playerMove == "q") return 0;

		// Undo a move if the player inputs 'u' to undo
		else if (playerMove == "u") {

			// Undo the move or reset to initial state if all moves are undone
			if (!boardStack.isEmpty()) boardStack.pop();
			else {
				std::cout << "\nCANNOT UNDO." << std::endl;
				showBoard = false;
				continue;
			}

			// Update the board state
			if (!boardStack.isEmpty()) {
				board = boardStack.topBoard();
				if (currentPlayer == &player1)
					player2 = boardStack.topPlayer('R');
				else
					player1 = boardStack.topPlayer('Y');
			}
			else {
				board = Board();
				player1 = Player('Y');
				player2 = Player('R');
			}
			
			currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
			continue;
		}	

		// Play a move if it is valid
		else {
			char pieceSize = playerMove[0];
			int position = playerMove[1] - '1';
			std::string piece = (pieceSize == 'a') ? (currentPlayer->getPieceColor() == 'Y' ? "YY" : "RR") : (pieceSize == 'b') ? std::string(1, toupper(currentPlayer->getPieceColor())) : std::string(1, tolower(currentPlayer->getPieceColor()));

			if (board.canPlacePiece(position, piece, pieceSize)) {
				board.placePiece(position, piece, pieceSize);

				// Push board to the stack to keep track of board states
				boardStack.push(board, player1, player2);
				currentPlayer->updatePieceCount(pieceSize);

				// Print a winner if there is one
				if (board.checkWin(piece)) {
					board.displayBoard();
					std::cout << (currentPlayer->getPieceColor() == 'Y' ? "\nYellow Wins!" : "\nRed Wins!") << std::endl;
					gameRunning = false;
				}

				// Tie game if both players run out of pieces
				else if (board.checkTie(currentPlayer == &player1 ? &player2 : &player1)) {
					board.displayBoard();
					std::cout << "\nTie game." << std::endl;
					gameRunning = false;
				}

				// Another player's turn
				 currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
			}
			else {
				std::cout << "\nCANNOT PLACE PIECE. TRY AGAIN." << std::endl;
				showBoard = false;
			}
		}
	}

	return 0;
}