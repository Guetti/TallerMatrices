#include "LinkedListPuzzle.h"

LinkedListPuzzle::LinkedListPuzzle()
{
	this->head = nullptr;
	this->size = 0;
}

LinkedListPuzzle::LinkedListPuzzle(PuzzleNode* puzzleNode)
{
	this->head = puzzleNode;
	this->size = 0;
	this->head->setNext(this->head);
}

PuzzleNode* LinkedListPuzzle::getHead()
{
	return this->head;
}

void LinkedListPuzzle::setHead(PuzzleNode* puzzleNode)
{
	this->head = puzzleNode;
}

int LinkedListPuzzle::getSize()
{
	return this->size;
}

void LinkedListPuzzle::setSize(int size)
{
	this->size = size;
}

bool LinkedListPuzzle::insert(PuzzleNode* puzzleNode)
{
	if (head == nullptr) { // Insertar en la cabeza
		this->head = puzzleNode;
		puzzleNode->setNext(puzzleNode);
		return true;
	}
	if (this->head->getNext() == this->head) { // Insertar en el siguiente a la cabeza
		this->head->setNext(puzzleNode);
		puzzleNode->setNext(this->head);
		return true;
	}
	PuzzleNode* aux = this->head;
	while (aux->getNext() != this->head) {
		aux = aux->getNext();
	}
	aux->setNext(puzzleNode);
	puzzleNode->setNext(this->head);

	return true;
}
