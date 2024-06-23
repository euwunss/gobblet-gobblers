#ifndef BOARDSTACK_H
#define BOARDSTACK_H

#include "Board.h"
#include "Player.h"

class BoardStack {
public:
	BoardStack();
	~BoardStack();
	void push(const Board& board, const Player& player1, const Player& player2);
	void pop();
	const Board& topBoard() const;
	const Player& topPlayer(char pieceColor) const;
	bool isEmpty() const;

private:
	struct BoardNode {
		Board board;
		Player player1;
		Player player2;
		BoardNode* next;
	};

	BoardNode* head;
};



#endif // !BOARDSTACK_H
