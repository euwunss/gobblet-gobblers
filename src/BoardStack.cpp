#include <iostream>

#include "../include/BoardStack.h"

BoardStack::BoardStack() : head(nullptr) {}

BoardStack::~BoardStack() {
	while (!isEmpty()) pop();
}

// Push the board state after a move was made
void BoardStack::push(const Board& board, const Player& player1, const Player& player2) {
	BoardNode* newNode = new BoardNode{board, player1, player2, head};
	head = newNode;
}

// Remove the top board state to undo
void BoardStack::pop() {
	if (isEmpty()) throw std::out_of_range("Board stack is empty.");

	BoardNode* temp = head;
	head = head->next;
	delete temp;
}

// Return the last saved board state
const Board& BoardStack::topBoard() const {
	if (isEmpty()) throw std::out_of_range("There was no previos move.");
	return head->board;
}

// Return the last saved player1 move
const Player& BoardStack::topPlayer(int i) const {
	if (isEmpty()) throw std::out_of_range("There was no previos move.");
	return (i == 1) ? head->player1 : head->player2;
}

// Check if the board stack is empty
bool BoardStack::isEmpty() const {
	return head == nullptr;
}