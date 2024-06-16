#include <iostream>
#include <string>
#include <vector>

#include "../include/Board.h"
#include "../include/Player.h"

int main() {
	std::cout << "*********** GOBBLET AND GOBBLERS  ***********";

	// Create a board and two players
	Board board;
	Player player1('Y'), player2('R');
	Player* currentPlayer = &player1;
	bool endGame = false;

	return 0;
}

